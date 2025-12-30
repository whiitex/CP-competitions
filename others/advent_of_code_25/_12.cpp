#include <bits/stdc++.h>
using namespace std;

#define int long long


string PATH = std::filesystem::current_path().parent_path().string();

vector<string> split(const string &s, const char _=' ') {
	vector<string> ans;
	int n = (int)s.size();
	for (int i=0; i<n; ++i) if (s[i] != _) {
		ans.emplace_back("");
		while (s[i] != _ and i < n) ans.back().push_back(s[i++]);
	}
	return ans;
}

void solve1(auto &tiles, auto &shapes, auto &req, string &file) {

	int n = (int)shapes.size();

	vector<int> sz((int)tiles.size());
	for (int i=0; i<(int)tiles.size(); ++i) {
		for (string &s: tiles[i]) for (char c: s) sz[i] += c == '#';
	}

	int ans = 0;

	for (int i=0; i<n; ++i) {
		int tot = 0;
		for (int j=0; j<(int)sz.size(); ++j) {
			tot += sz[j] * req[i][j];
		}
		ans += shapes[i].first * shapes[i].second > tot + 300;
	}

	cout << "part 1 - " << file << ": " << ans << endl;
}

void solve(ifstream &fin, string &file) {

	string s;
	vector<vector<string>> tiles(6);
	for (int i=0; i<6; ++i) {
		fin >> s;
		for (int j=0; j<3; ++j) {
			fin >> s; tiles[i].push_back(s);
		}
	}

	getline(fin, s);
	getline(fin, s);

	vector<pair<int,int>> shapes;
	vector<vector<int>> req;

	while (getline(fin, s)) {
		vector<string> spl = split(s);
		int n1 = 0, n2 = 0, i = 0;
		while (isdigit(spl[0][i])) n1 = n1 * 10 + (spl[0][i++] - '0');
		++i;
		while (isdigit(spl[0][i])) n2 = n2 * 10 + (spl[0][i++] - '0');

		shapes.push_back({n1, n2});
		vector<int> cur;
		for (int i=1; i<(int)spl.size(); ++i) {
			int num = (spl[i][0] - '0') * 10 + (spl[i][1] - '0');
			cur.push_back(num);
		}
		req.push_back(cur);
	}


	solve1(tiles, shapes, req, file);
}

signed main() {
	for (string file: {"test", "input"}) {
		ifstream fin(PATH + "/others/advent_of_code_25/" + file + ".txt");
		if (!fin) { cerr << "Error: Input file not found!"; return 1; }

		solve(fin, file);
		fin.close();
	}
}