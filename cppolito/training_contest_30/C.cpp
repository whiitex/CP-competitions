#include <bits/stdc++.h>

using namespace std;

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

#define int long long

typedef pair<int,int> pii;
#define pb push_back

const int INF = 1e9;

int triangle(int n) { return n * (n+1) / 2; }

int compute(int a, int b, int c) {
	if (a >= b and c >= b) return triangle(b+1);

	if (a < c) swap(a, c);
	if (a >= b or c >= b) {
		return triangle(b+1) - triangle(b - c);
	}

	int ans = (a+1) * min((b-a), c+1);
	if (b-a <= c) ans += triangle(a+1) - triangle(b-c);
	return ans;
}

void solve() {
	string s; cin >> s;
	int n = (int)s.length();

	set<int> non_a;
	for (int i=0; i<n; ++i) if (s[i] != 'a')
		non_a.insert(i);
	non_a.insert(10 * n);

	int start_a = 0, end_a = 0;
	while (start_a < n and s[start_a] == 'a') ++start_a;
	while (end_a < n and s[n-1-end_a] == 'a') ++end_a;

	string_hash hs(s);


	function check = [&] (int pos, int sz) -> pii {
		int i = *non_a.begin(), space = INF, rep = 0;
		while (i < n) {
			if (i + sz > n) return {0, 0};
			if (!hs.equal(pos, i, sz)) return {0,0};

			int nxt = *non_a.lower_bound(i + sz);
			space = min(space, nxt - i - sz);
			i = nxt; ++rep;
		} return {rep, space};
	};

	int ans = 0;
	for (int i=start_a; i<n-end_a; ++i) {
		if (s[i] != 'a') {
			pii res = check(i, n - i - end_a);
			int rep = res.first, space = res.second;
			if (rep == 0) continue;

			int sx_space = min(space, start_a);
			int rx_space = min(space, end_a);

			if (rep == 1) ans += (start_a+1) * (end_a+1);
			else ans += compute(sx_space, space, rx_space);
		}
	}

	if (count(s.begin(), s.end(), 'a') == n) ans = n-1;
	cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
