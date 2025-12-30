#include <bits/stdc++.h>
using namespace std;

#define int long long


string PATH = std::filesystem::current_path().parent_path().string();

void solve(ifstream &fin, ostream &cout) {
	vector<string> g; string s;
	while (fin >> s) g.push_back(s);

	int ans = 0, n = (int)g.size(), m = (int)g[0].size(), go = 1;
	while (go) {
		go = 0;
		for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (g[i][j] == '@') {
			int cnt = 0;
			for (int dx: {-1, 0, 1}) for (int dy: {-1, 0, 1}) {
				if ((dx or dy) and i + dx >= 0 and i + dx < n and j + dy >= 0 and j + dy < m) {
					cnt += g[i + dx][j + dy] == '@';
				}
			}
			if (cnt < 4) {
				++ans;
				go = 1;
				g[i][j] = '.';
			}
		}
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