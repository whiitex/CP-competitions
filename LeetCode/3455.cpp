mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));

using hash_t = uint64_t;

// When P = 2^32 - 13337, both P and (P - 1) / 2 are prime.
const hash_t HASH_P = (unsigned) - 13337;

// Avoid multiplication bases near 0 or P - 1.
uniform_int_distribution<hash_t> MULT_DIST(0.1 * HASH_P, 0.9 * HASH_P);
const hash_t HASH_MULT[] = {MULT_DIST(rng), MULT_DIST(rng)};
const int HASH_COUNT = 2;

vector<unsigned> hash_pow[HASH_COUNT];

struct string_hash {
    vector<unsigned> prefix_hash[HASH_COUNT];
    string result;

    string_hash() {}

    template<typename T_string>
    string_hash(const T_string &str) {
        build(str);
    }

    int length() const {
        return max((int) prefix_hash[0].size() - 1, 0);
    }

    template<typename T_string>
    void build(const T_string &str) {
        for (int h = 0; h < HASH_COUNT; h++) {
          	if (hash_pow[h].empty())
            	hash_pow[h] = {1};

          	while (hash_pow[h].size() <= str.size())
           		hash_pow[h].push_back(HASH_MULT[h] * hash_pow[h].back() % HASH_P);

          	prefix_hash[h].resize(str.size() + 1);
          	prefix_hash[h][0] = 0;

          	for (int i = 0; i < (int) str.size(); i++)
            	prefix_hash[h][i + 1] = (HASH_MULT[h] * prefix_hash[h][i] + str[i]) % HASH_P;
        }
    }

    void add_char(char c) {
		result.push_back(c); // original: result += c;

	    for (int h = 0; h < HASH_COUNT; h++) {
	    	if (hash_pow[h].empty()) hash_pow[h] = {1};
	        hash_pow[h].push_back(HASH_MULT[h] * hash_pow[h].back() % HASH_P);
	        if (prefix_hash[h].empty()) prefix_hash[h] = {0};
	        prefix_hash[h].push_back((HASH_MULT[h] * prefix_hash[h].back() + c) % HASH_P);
	    }
    }

    hash_t _substring_hash(int h, int start, int end) const {
	    hash_t start_hash = (hash_t) prefix_hash[h][start] * hash_pow[h][end - start];
    	return (prefix_hash[h][end] + HASH_P * HASH_P - start_hash) % HASH_P;
    }

    hash_t combined_hash(int start, int end) const { // (i, i + length) for substr of size 'length'
      	return _substring_hash(0, start, end) + (HASH_COUNT > 1 ? _substring_hash(1, start, end) << 32 : 0);
    }

	// check  two substrings starting at positions 'start1' and 'start2' and having length 'len'
	bool equal(int start1, int start2, int len) {
	    return this->combined_hash(start1, start1 + len) == this->combined_hash(start2, start2 + len);
    }
};

// class Solution
class Solution {
public:
    int shortestMatchingSubstring(string s, string p) {
    	// **
        if (p.size() == 2) return 0;
        string S = s + p;
    	string_hash hasher(S);

    	set<int> a, b, c;
    	int ia=0, ib, ic, n=s.size();
    	while (p[ia] != '*') ++ia;
    	if (ia != 0) for (int i=0; i+ia <= s.size(); ++i) {
    		if (hasher.equal(i, s.size(), ia)) a.insert(i);
    	} else for (int i=0; i<=n; ++i) a.insert(i);

    	ib = ia+1; while (p[ib] != '*') ++ib;
    	if (ib > ia+1) for (int i=0; i+ib-ia-1 <= s.size(); ++i) {
    		if (hasher.equal(i, s.size()+ia+1, ib-ia-1)) b.insert(i);
    	} else for (int i=0; i<=n; ++i) b.insert(i);

    	ic = ib+1;
    	if (ic < p.size()) for (int i=0; i+p.size()-ic <= s.size(); ++i) {
    		if (hasher.equal(i, s.size()+ic, p.size()-ic)) c.insert(i);
    	} else for (int i=0; i<=n; ++i) c.insert(i);

    	int lna = ia, lnb = ib-ia-1, lnc = p.size()-ic;

    	int ans = 100000000;
    	for (int i: a) {
	    	auto it = b.lower_bound(i + lna);
    		if (it == b.end()) continue;
    		auto it2 = c.lower_bound(*it + lnb);
    		if (it2 == c.end()) continue;
    		ans = min(ans, *it2 + lnc - i);
    	}

    	if (ans == 100000000) ans = -1;
    	return ans;
    }
};