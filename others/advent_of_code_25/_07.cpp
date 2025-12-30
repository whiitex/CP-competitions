#include <bits/stdc++.h>
using namespace std;

#define int long long


string PATH = std::filesystem::current_path().parent_path().string();

void solve(ifstream &fin, ostream &cout) {
	vector<string> g; string s;
	while (fin >> s) g.push_back(s);

	int n = g.size(), m = g[0].size();
	vector dp(n, vector<int>(m, 0));
	for (int i=0; i<n - 1; i++) for (int j=0; j<m; j++) {
		if (g[i][j] == 'S') dp[i][j] = 1;
	}

	for (int i=0; i<n-1; i++) for (int j=0; j<m; j++) {
		if (g[i+1][j] == '.') {
			dp[i+1][j] += dp[i][j];
		} else if (g[i+1][j] == '^') {
			dp[i+1][j-1] += dp[i][j];
			dp[i+1][j+1] += dp[i][j];
		}
	}

	int ans = 0;
	for (int i=0; i<m; ++i) ans += dp[n-1][i];
	cout << ans << endl;
}

signed main() {
	for (string file: {"test", "input"}) {
		ifstream fin(PATH + "/others/advent_of_code_25/" + file + ".txt");
		if (!fin) { cerr << "Error: Input file not found!"; return 1; }

		solve(fin, file == "test" ? cerr : cout);
		fin.close();
	}
}