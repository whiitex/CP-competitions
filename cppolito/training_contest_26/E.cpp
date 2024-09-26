#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n, q; cin >> n >> q;
    vi color(n+1);
    for (int i=1; i<=n; ++i) cin >> color[i];
    vector<vi> adj(n+1, vi());
    for (int i=0; i<n-1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int tot_blacks = 0;
    vi black_ch_count(n+1);
    set<int> black_ch;
    int white_count = 0;

    vi par(n+1, 0);
    function<void(int)> dfs = [&] (int node) -> void {
        if (color[node]) ++tot_blacks;
        
        int count = 0;
        for (int ch: adj[node]) {
            if (ch != par[node]) {
                par[ch] = node;
                if (color[ch]) ++count;
                dfs(ch);
            }
        }
        if (count > 1) black_ch.insert(node);
        if (color[node] and !color[par[node]]) ++white_count;

        black_ch_count[node] = count;
    };
    
    dfs(1);

    while (q--) {
        int toggle; cin >> toggle;
        int parent = par[toggle];
        
        // upd total blacks
        if (color[toggle]) --tot_blacks;
        else ++tot_blacks;
        
        // upd white_count
        if (color[toggle]) {
            if (!color[parent]) --white_count;
            white_count += black_ch_count[toggle];
        }
        else {
            if (!color[parent]) ++white_count;
            white_count -= black_ch_count[toggle];
        }
        
        // upd black ch count
        if (color[toggle]) --black_ch_count[parent];
        else ++black_ch_count[parent];
        
        // upd set black ch
        if (black_ch_count[parent] <= 1) black_ch.erase(parent);
        else black_ch.insert(parent);

        // upd color
        color[toggle] ^= 1;

        // ANSWER
        if (tot_blacks == 0 or white_count > 1 or (!black_ch.empty() and black_ch.size() > 1))
            cout << "No" << '\n';
        else if (white_count == 1) {

            if (black_ch.empty()) cout << "Yes" << '\n';

            else if (black_ch.size() == 1) {
                int more_ch_node = *black_ch.begin();
                if (!color[par[more_ch_node]] and black_ch_count[more_ch_node] == 2)
                    cout << "Yes" << '\n';
                else cout << "No" << '\n';
            }
            else cout << "No" << '\n';
        }
        else cout << "No" << '\n';
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
