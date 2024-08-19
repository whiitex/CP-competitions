class Solution {
public:
	int numDistinct(string s, string t) {
		int n = s.size();
		vector<long long> dp(n, 0);
		for (int i=0; i<n; ++i) if (s[i] == t[0]) ++dp[i];

		for (int j=1; j<t.size(); ++j) {
			int sum = 0;
			for (int i=0; i<n; ++i) {
				sum += dp[i];
				if (s[i] == t[j]) dp[i] = sum - dp[i];
				else dp[i] = 0;
			}
		}

		return accumulate(dp.begin(), dp.end(), 0);
	}
};