#include <bits/stdc++.h>
using namespace std;

#define int long long


string PATH = std::filesystem::current_path().parent_path().string();

void solve(ifstream &fin, ostream &cout) {
	int ans = 0;

	string line;
	while (fin >> line) {
		int n = (int)line.size();
		vector dp(n+1, vector<int>(13, 0));
		for (int sz=1, ten=1; sz<=12; ++sz, ten*=10) {
			for (int i=n-sz; i>=0; --i) {
				int x = line[i] - '0';
				dp[i][sz] = max(dp[i+1][sz], dp[i+1][sz-1] + x * ten);
			}
		}
		ans += dp[0][12];
	}

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