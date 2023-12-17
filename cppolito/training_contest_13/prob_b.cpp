#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

class Node {
public:
    int i;
    vector<Node*> children;
    explicit Node(int in) {i = in;}
};

void solve() {
    int n; cin >> n;
    vector<Node*> vec(n+1);
    vector<int> res(n);
    map<pair<int,int>,int> m;
    for (int i=1; i<n+1; ++i) {
        Node *node = new Node(i);
        vec[i] = node;
    }

    for (int i=1; i<n; ++i) {
        int v, u;
        cin >> v >> u;
        vec[v]->children.push_back(vec[u]);
        vec[u]->children.push_back(vec[v]);
        m.insert({{min(u,v), max(u,v)},i});

    }

    for (int i=1; i<=n; ++i) {
        if (vec[i]->children.size() > 2) {
            cout << -1 << '\n';
            return;
        }
    }


    int i = 1;
    while (vec[i]->children.size() > 1) ++i;

    Node* node = vec[i];
    vector<bool> visited(n+1, false);
    queue<int> que;
    que.push(node->children[0]->i);
    visited[i] = true;
    int val = 11;
    while (!que.empty()) {
        Node* next = vec[que.front()];
        visited[next->i] = true;
        que.pop();
        for (auto ch: next->children)
            if (!visited[ch->i])
                que.push(ch->i);

        pair<int,int> pr = {min(node->i, next->i), max(node->i, next->i)};
        res[m[pr]] = 13 - val;
        val = 13 - val;
        node = next;
    }

    for (int ii=1; ii<n; ++ii)
        cout << res[ii] << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}