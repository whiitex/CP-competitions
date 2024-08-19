class Solution {
public:
	string minWindow(string s, string t) {
		int m = s.size(), tot = 0;
		unordered_map<char, int> check, mp;

		for (char c: t) ++check[c];
		for (auto p: check) ++tot;

		int l=0, len=1e6, j=0, now=0;
		for (int i=0; i<m; ++i) {
			char c = s[i];

			++mp[c];
			if (mp[c] == check[c]) ++now;

			while (now == tot and j <= i) {
				c = s[j];
				if (i - j + 1 < len) {
					l = j; len = i - j + 1;
				}

				--mp[c];
				if (check[c] and mp[c] == check[c] - 1) --now;
				++j;
			}
		}

		if (len == 1e6) return "";
		else return s.substr(l, len);
	}
};