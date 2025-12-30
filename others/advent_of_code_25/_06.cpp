#include <bits/stdc++.h>
using namespace std;

#define int long long


string PATH = std::filesystem::current_path().parent_path().string();

void solve(ifstream &fin, ostream &cout) {
	vector<string> in; string line;
	while (getline(fin, line)) in.push_back(line);

	vector<char> op;
	for (int i=0; i<(int)in.back().size(); ++i) {
		op.push_back(in.back()[i]); ++i;
		while (i < (int)in.back().size() and in.back()[i] == ' ') ++i;
		--i;
	}

	int ans = 0, n = op.size();
	for (int col=n-1, i=in[0].size()-1; col>=0; --col, --i) {

		vector<int> g;
		while (i >= 0) {
			int all_spaces = 1, x = 0;
			for (int row=0; row<(int)in.size()-1; ++row) {
				if (in[row][i] != ' ') {
					all_spaces = 0;
					x = x * 10 + (in[row][i] - '0');
				}
			}

			if (all_spaces) break;
			g.push_back(x);
			--i;
		}

		int res= g[0];
		for (int j=1; j<(int)g.size(); ++j) {
			if (op[col] == '+') res += g[j];
			else res *= g[j];
		}

		ans += res;
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