//NEAL_WU Hash
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

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int totln = words.size() * words[0].size(), wordsz = words[0].size();

        string_hash hs(s);
        vector<hash_t> hw;
        for (string q: words) {
            string_hash hq(q);
            hw.push_back(hq.combined_hash(0, wordsz));
        }

        vector<int> ans;
        unordered_map<hash_t, int> mp;
        for (hash_t h: hw) ++mp[h];

        for (int i=0; i<=min((int)s.size()-wordsz, wordsz-1); ++i) {
            int rem = words.size();
            unordered_map<hash_t, int> mprem(mp);

            for (int j=i; j<=s.size()-wordsz; j+=wordsz) {
                if (mprem[hs.combined_hash(j, j + wordsz)] > 0) {
                    --mprem[hs.combined_hash(j, j + wordsz)];
                    --rem;
                    if (rem == 0) {
                        int start = j + wordsz - totln;
                        ans.push_back(start);
                        ++mprem[hs.combined_hash(start, start + wordsz)];
					    ++rem;
                    }
                } else {
                    mprem = mp;
                    if (mprem[hs.combined_hash(j, j + wordsz)] > 0)
					    j -= wordsz * (words.size() - rem);
                    rem = words.size();
			    }
            }
        }

        return ans;
    }
};