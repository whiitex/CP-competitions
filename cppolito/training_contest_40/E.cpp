#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

int hsh(string s) {
    int h = 0, m = 1;
    for (char c: s) {
        if (c == '_') h += 29 * m;
        else h += (c - 'a' + 1) * m;
        m *= 30;
    }
    return h;
}

const int MXN = hsh("____") + 1;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<string> pat(n); for (string &s: pat) cin >> s;
    vector<tuple<string, int>> txt(m);
    for (auto &[s, i]: txt) cin >> s >> i;

    vi idx(MXN, -1); for (int i=0; i<n; ++i) {
        idx[hsh(pat[i])] = i + 1;
    }

    auto extract = [&idx, &k] (string &s) -> set<int> {
        set<int> ret;
        for (int mask = 0; mask < (1 << k); ++mask) {
            string t = s;
            for (int i=0; i<k; ++i) {
                if (mask & (1 << i)) t[i] = '_';
            }
            int h = hsh(t);
            if (idx[h] != -1) ret.insert(idx[h]);
        } return ret;
    };

    vector adj(n+1, set<int>());
    for (auto &[t, pos]: txt) {
        set<int> st = extract(t);
        if (!st.contains(pos)) { cout << "NO"; return; }
        for (int i: st) if (i != pos) adj[pos].insert(i);
    }

    int no = 0;
    vi vis(n+1), ans;
    auto dfs = [&] (auto f, int u) -> void {
        if (no) return;
        vis[u] = 1;

        for (int v: adj[u]) {
            if (!vis[v]) f(f, v);
            else if (vis[v] == 1) no = 1;
        }

        vis[u] = 2;
        ans.pb(u);
    };

    for (int i=1; i<=n; ++i) if (!vis[i]) dfs(dfs, i);

    if (no) { cout << "NO"; return; }

    cout << "YES\n";
    reverse(ans.begin(), ans.end());
    for (int i: ans) cout << i << ' ';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}
