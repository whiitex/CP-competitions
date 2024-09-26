#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef __int128_t lll; typedef long double ld;
typedef pair<int,int> pii; typedef pair<ld,ld> pld;
typedef vector<int> vi; typedef vector<pii> vpii;

#define pb push_back
#define f first
#define s second

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;


int ask(int u, int v) {
    cout << "? " << u << ' ' << v << endl;
    int w; cin >> w; return w;
}

void answer(int u) {
    cout << "! " << u << endl;
}

void solve() {
    int n; cin >> n;
    vector adj(n+1, set<int>());
    for (int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<bool> visited(n+1, 0);
    int queries = n >> 1;
    queue<int> q;
    for (int i=1; i<=n; ++i)
        if (!adj[i].empty() and adj[i].size() == 1)
            q.push(i);
    while (queries--) {
        int u = q.front(); q.pop();
        int v = q.front(); q.pop();
        int w = ask(u, v);
        visited[u] = visited[v] = 1;

        if (w == u or w == v) {
            answer(w); return;
        }
        for (int z: {u,v}) {
            for (int par: adj[z]) {
                adj[par].erase(z);
                if (!adj[par].empty() and adj[par].size() == 1)
                    q.push(par);
            }
        }
    }

    for (int i=1; i<=n; ++i) if (!visited[i]) answer(i);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();
}
