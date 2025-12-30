#include <bits/stdc++.h>
using namespace std;

#define int long long


string PATH = std::filesystem::current_path().parent_path().string();

void solve(ifstream &fin, ostream &cout) {
	int x = 50, mod = 100, ans = 0;

	char c; int move;
	while (fin >> c >> move) {
		if (c == 'L') move = -move;
		int d = move / mod;
		move -= d * mod;
		ans += abs(d);

		if (x > 0) {
			if (c == 'L' and abs(move) >= x and abs(move)) ++ans;
			if (c == 'R' and move >= 100 - x and abs(move)) ++ans;
		}

		// cout << c << " " << move << " " << x << " " << ans << endl;
		x = (x + move + mod) % mod;
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