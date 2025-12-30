#include <bits/stdc++.h>
using namespace std;

#define int long long


string PATH = std::filesystem::current_path().parent_path().string();

void solve(ifstream &fin, ostream &cout) {

	vector<pair<int,int>> a;
	string s; while (fin >> s) {
		int x = 0, y = 0, i = 0;
		while (s[i] != ',') x = x * 10 + (s[i++] - '0');
		i++;
		while (i < s.size()) y = y * 10 + (s[i++] - '0');
		a.push_back({x, y});
	}

	int ans = 0, n = (int)a.size();

	// int finalx, finaly;

	// go down
	int X = 94553, Y = 48602, miny = 1e9;
	for (int i=0; i<n; ++i) if (a[i].second < Y) {
		auto [x, y] = a[i];
		auto [x1, y1] = a[(i+1)%n];

		if (x == X and y == Y) continue;
		if (x1 == X and y1 == Y) continue;

		if (min(x, x1) <= X and X <= max(x, x1)) {
			miny = min(y, y1);
		}
	}
	for (int i=0; i<n; ++i) {
		auto [x, y] = a[i];
		if (y > Y or y < miny or x >= X) continue;
		// if (ans < (X - x + 1) * (Y - y + 1)) {
		// 	finalx = x;
		// 	finaly = y;
		// 	ans = (X - x + 1) * (Y - y + 1);
		// }
		ans = max(ans, (X - x + 1) * (Y - y + 1));
		// cout << x << ' ' << y << endl;
	}
	// cout << endl;

	// go up
	Y = 50158; int maxy = -1e9;
	for (int i=0; i<n; ++i) if (a[i].second > Y) {
		auto [x, y] = a[i];
		auto [x1, y1] = a[(i+1)%n];

		if (x == X and y == Y) continue;
		if (x1 == X and y1 == Y) continue;

		if (min(x, x1) <= X and X <= max(x, x1)) {
			maxy = max(y, y1);
		}
	}
	for (int i=0; i<n; ++i) {
		auto [x, y] = a[i];
		if (x == 5000) continue;
		if (y < Y or y > maxy or x >= X) continue;
		// if (ans < (X - x + 1) * (y - Y + 1)) {
		// 	finalx = x;
		// 	finaly = y;
		// 	ans = (X - x + 1) * (y - Y + 1);
		// }
		ans = max(ans, (X - x + 1) * (y - Y + 1));
		// cout << x << ' ' << y << endl;
	}
	// cout << endl;

	// cout << finalx << ' ' << finaly << endl << endl;
	cout << ans << endl;
}

signed main() {
	for (string file: {"input"}) {
		ifstream fin(PATH + "/others/advent_of_code_25/" + file + ".txt");
		if (!fin) { cerr << "Error: Input file not found!"; return 1; }

		solve(fin, file == "test" ? cerr : cout);
		fin.close();
	}
}