#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> adj(n+1, vi());
    for (int i=0; i<m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bool is_biparted = true;

    vi visited(n+1, 0);
    queue<int> q;
    for (int i=1; i<=n; ++i) {
        if (visited[i]) continue;

        q.push(i); visited[i] = 1;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int ch: adj[node]) {
                if (!visited[ch]) {
                    visited[ch] = visited[node] == 1 ? 2 : 1;
                    q.push(ch);
                } else if (visited[ch] == visited[node])
                    is_biparted = false;
            }
        }
    }

    if (!is_biparted) {
        cout << "Alice" << endl;
        for (int i=0; i<n; ++i) {
            cout << "1 2" << endl;
            int trash;
            cin >> trash >> trash;
        }
        return;
    }

    vi one, two;
    for (int i=1; i<=n; ++i) {
        if (visited[i] == 1) one.pb(i);
        else two.pb(i);
    }

    cout << "Bob" << endl;
    int c, k, c1, c2;
    cin >> c >> k;

    cout << one.back() << ' ' << c << endl;
    one.pop_back();


    for (int i=1; i<n; ++i) {
        cin >> c1 >> c2;
        if ((c1 == c or c2 == c) and !one.empty()) {
            cout << one.back() << ' ' << c << endl;
            one.pop_back();
        } else if ((c1 == k or c2 == k) and !two.empty()) {
            cout << two.back() << ' ' << k << endl;
            two.pop_back();
        } else {
            if (!one.empty()) {
                cout << one.back() << ' '  << (c1 == k ? c2 : c1) << endl;
                one.pop_back();
            } else {
                cout << two.back() << ' ' << (c1 == c ? c2 : c1) << endl;
                two.pop_back();
            }
        }
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
