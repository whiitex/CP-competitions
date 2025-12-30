#include <bits/stdc++.h>
using namespace std;

#define int long long


string PATH = std::filesystem::current_path().parent_path().string();

void solve(ifstream &fin, ostream &cout) {
	vector<pair<int,int>> ranges;
	string line; getline(fin, line);
	while (line != "") {
		int x = 0, y = 0, i = 0;
		while (line[i] != '-') x = x * 10 + (line[i++] - '0'); ++i;
		while (i < line.size()) y = y * 10 + (line[i++] - '0');
		ranges.push_back({x, y});
		getline(fin, line);
	}

	sort(ranges.begin(), ranges.end());

	int ans = 0;
	for (int i=0, mx=-1; i<ranges.size(); ++i) {
		auto &[l, r] = ranges[i];
		if (l > mx) ans += r - l + 1, mx = r;
		else ans += max(0ll, r - mx), mx = max(mx, r);
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