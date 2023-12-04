#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const ll MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

class Node {
public:
    ll i;
    vector<Node*> children;
    Node(ll index) {
        i = index;
    }
};

void solve() {

    // init
    ll n, m; cin >> n >> m;
    ll kp, km; cin >> kp >> km;
    vector<Node*> vec(n);
    for (ll i=0; i<n; ++i) {
        Node* node = new Node(i);
        vec[i] = node;
    }
    for (ll i=0; i<m; ++i) {
        ll u,v; cin >> u >> v;
        vec[u-1]->children.push_back(vec[v-1]);
        vec[v-1]->children.push_back(vec[u-1]);
    }

    // solve
    vector<bool> visited(n,false);
    ll res=0;
    ll self_graph = 0;
    for (ll i=0; i<n; ++i) {
        if (!visited[i]) {

            ll edges = 0, nodes = 1;
            queue<ll> que;
            que.push(i);

            // visit all nodes connected to this one
            while (!que.empty()) {
                visited[i] = true;
                Node* nownode = vec[que.front()];
                que.pop();
                edges += (ll)nownode->children.size(); // counted two times
                for (auto c: nownode->children) {
                    if (!visited[c->i]) {
                        visited[c->i] = true;
                        que.push(c->i);
                        ++nodes;
                    }
                }
            }
            ll cost = km * (edges - 2 * (nodes - 1)) / 2;
            if (cost>0) res += cost;

            // count num of graphs not linked each other
            ++self_graph;
        }
    }

    res += kp * (self_graph - 1);
    cout << res;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}