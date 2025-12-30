#include <bits/stdc++.h>
using namespace std;

#define int long long


string PATH = std::filesystem::current_path().parent_path().string();

void solve(ifstream &fin, ostream &cout) {
	int ans = 0;

	int l, r; char c;
	do {
		fin >> l >> c >> r;
		unordered_set<int> seen;
		for (int i=1; ; ++i) {
			string s = to_string(i);
			string ss = s + s;
			if (stoll(ss) > r) break;


			for (int rep=2; rep<=18/s.size(); ++rep) {
				int num = stoll(ss);
				if (num >= l and num <= r and !seen.contains(num)) {
					ans += num;
					seen.insert(num);
				}
				ss.append(s);
			}
		}
	} while (fin >> c);

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