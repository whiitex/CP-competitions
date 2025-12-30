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

void solve1(auto &adj, int source, int sink, string &file) {

	int ans = 0;
	auto dfs = [&](auto f, int u) -> void {
		if (u == sink) { ++ans; return; }
		for (int v: adj[u]) f(f, v);
	};
	dfs(dfs, source);

	cout << "part 1 - " << file << ": " << ans << endl;
}

void solve2(auto &adj, int source, int sink, int need1, int need2, string &file) {

	map<int,int> vis;
	vector<int> topo;
	auto dfs = [&](auto f, int u) -> void {
		++vis[u];
		for (int v: adj[u]) if (!vis.contains(v)) {
			f(f, v);
		} topo.push_back(u);
	};
	for (auto &[k, _]: adj) if (!vis.contains(k)) {
		dfs(dfs, k);
	}

	reverse(topo.begin(), topo.end());

	int ans = 0;

	map<int, array<int,4>> dp; // node -> {from svr, met dac, met fft, met both}
	dp[source][0] = 1;
	for (int i=0; i<(int)topo.size(); ++i) {

		int u = topo[i];
		if (u == sink) { ans = dp[u][3]; break; }

		for (int v: adj[u]) {

			if (v == need1) {
				dp[v][0] += dp[u][0];
				dp[v][1] += dp[u][0];
				dp[v][3] += dp[u][2];
			} else if (v == need2) {
				dp[v][0] += dp[u][0];
				dp[v][2] += dp[u][0];
				dp[v][3] += dp[u][1];
			} else {
				dp[v][0] += dp[u][0];
				dp[v][1] += dp[u][1];
				dp[v][2] += dp[u][2];
				dp[v][3] += dp[u][3];
			}
		}
		if (u == need1) dp[u][1] += 1;
		if (u == need2) dp[u][2] += 1;
	}

	cout << "part 2 - " << file << ": " << ans << endl;
}

void solve(ifstream &fin, string &file) {

	auto key = [&](string s) -> int {
		int ans = 0, pow = 1;
		for (char c: s) {
			ans += (c - 'a' + 1) * pow;
			pow *= 27;
		} return ans;
	};

	map<int, vector<int>> adj;
	string line; while (getline(fin, line)) {
		vector<string> spl = split(line);
		spl[0].pop_back();
		for (int i=1; i<(int)spl.size(); ++i) {
			adj[key(spl[0])].push_back(key(spl[i]));
		}
	}


	solve1(adj, key("you"), key("out"), file);
	solve2(adj, key("svr"), key("out"), key("dac"), key("fft"), file);
}

signed main() {
	for (string file: {"test", "input"}) {
		ifstream fin(PATH + "/others/advent_of_code_25/" + file + ".txt");
		if (!fin) { cerr << "Error: Input file not found!"; return 1; }

		solve(fin, file);
		fin.close();
	}
}