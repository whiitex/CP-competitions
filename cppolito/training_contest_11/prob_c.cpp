#include <bits/stdc++.h>

using namespace std;
#define ll long long

class Node {
public:
    ll v;
    ll poss;
    vector<Node*> children;
    Node(ll value) { v = value; }
};

// Recursive DFS
ll func(Node* n, ll prev) {
    if (n->children.size() == 1 && n->v != 1) {
        n->poss = 1;
        return 1;
    }
    else {
        n->poss = 0;
        for(Node* node : n->children) {
            if (node->v != prev)
                n->poss += func(node, n->v);
        }
        return n->poss;
    }
}


void solve(){
    ll n, q;
    cin >> n;

    // INITIALIZATION
    Node* vec[n+1];
    for (ll i = 0; i <= n; i++)
        vec[i] = new Node(i);

    // GETTING EDGES
    for (ll i = 0; i < n-1; i++) {
        ll u, v;
        cin >> u >> v;
        vec[v]->children.push_back(vec[u]);
        vec[u]->children.push_back(vec[v]);
    }

    // recursion
    func(vec[1], 0);

    // SOLUTION
    cin >> q;
    while(q--) {
        ll x, y;
        cin >> x >> y;
        cout << vec[x]->poss * vec[y]->poss << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}
