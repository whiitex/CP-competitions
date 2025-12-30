#include <bits/stdc++.h>
using namespace std;

#define int long long


string PATH = std::filesystem::current_path().parent_path().string();


struct DSU {
	vector<int> Par, Sz;
	explicit DSU(int n): Par(n), Sz(n, 1) {
		iota(Par.begin(), Par.end(), 0);
	}

	int find(int node) {
		if (Par[node] == node) return node;
		return Par[node] = find(Par[node]);
	}

	void merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (Sz[a] < Sz[b]) swap(a, b);
		Par[b] = a; Sz[a] += Sz[b];
	}
};

void solve(ifstream &fin, ostream &cout) {

	vector<array<int,3>> pts;
	string s; while (fin >> s) {
		int x = 0, y = 0, z = 0, i = 0;
		while (s[i] != ',') x = x * 10 + (s[i++] - '0');
		i++;
		while (s[i] != ',') y = y * 10 + (s[i++] - '0');
		i++;
		while (i < s.size()) z = z * 10 + (s[i++] - '0');

		pts.push_back({x, y, z});
	}

	auto dist = [](array<int,3> &a, array<int,3> &b) -> int {
		int x = abs(a[0] - b[0]);
		int y = abs(a[1] - b[1]);
		int z = abs(a[2] - b[2]);
		return x * x + y * y + z * z;
	};

	int n = (int)pts.size();

	set<array<int,3>> connections; // dist, i, j
	for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
		int d = dist(pts[i], pts[j]);
		connections.insert({d, i, j});
	}

	DSU dsu(n);

	int ops = n - 1;
	for (auto [_, i, j]: connections) {
		if (dsu.find(i) != dsu.find(j)) {
			dsu.merge(i, j);
			--ops;
			if (ops == 0) {
				cout << pts[i][0] * pts[j][0] << endl;
				break;
			}
		}
	}
}

signed main() {
	for (string file: {"test", "input"}) {
		ifstream fin(PATH + "/others/advent_of_code_25/" + file + ".txt");
		if (!fin) { cerr << "Error: Input file not found!"; return 1; }

		solve(fin, file == "test" ? cerr : cout);
		fin.close();
	}
}