#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define st first
#define nd second

void solve() {
    int n; cin >> n;
    vector adj(101, set<int>());
    for (int i=0; i<n; ++i) {
        int u, v;
        scanf("%lld|%lld", &u, &v);
        adj[u].insert(v);
    }

    vector<vi> lst ={{38,33,35,91,62,74,57,54,15,73,64,61,65,32,25,19,21,39,58,26,79},
        {46,62,56,61,35,88,74},
        {24,17,55,67,42,16,58},
        {16,39,24,25,28,17,98,41,64,21,29,42,13,79,61,19,14,58,67,94,32},
        {34,56,97,37,38,33,35,91,62,54,15,73,64,42,65,32,17},
    };


    auto check = [&] (vi& vec) -> bool {
        vi vis(101);
        for (int u: vec) {
            vis[u] = 1;
            for (int v: adj[u]) if (vis[v]) return 0;
        }
        return 1;
    };

    int ans = 0;
    for (vi& vec: lst) {
        if (check(vec)) continue;

        for (int i=0; i<(int)vec.size(); ++i) {
            int go = 1;
            while (go) {
                int u = vec[i]; go = 0;
                for (int j=i+1; j<(int)vec.size(); ++j) {
                    if (adj[vec[j]].contains(u)) {
                        swap(vec[i], vec[j]);
                        go = 1; break;
                    }
                }
            }
        }
        ans += vec[vec.size()/2];
    }

    cout << ans << '\n';
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

