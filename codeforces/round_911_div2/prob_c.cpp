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
    char ch;
    bool exist;
    Node* left;
    Node* right;
    Node(char c, Node* l, Node* r) {
        ch = c;
        left = l;
        right = r;
    }
    Node() {exist = false;}
};

int rec(Node* node) {
    if ( !node->right->exist and !node->left->exist)
        return 0;
    else {
        int l=0,r=0;
        if (node->ch == 'L') r=1;
        else if (node->ch == 'R') l=1;
        else  {l=1; r=1;}
        if (!node->left->exist) return rec(node->right) + r;
        else if (!node->right->exist) return rec(node->left) + l;
        else return min(rec(node->left)+l, rec(node->right)+r);
    }
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<Node*> vec(n+1);
    for (int i=0; i<=n; ++i)
        vec[i] = new Node();
    for (int i=1; i<=n; ++i) {
        int l,r; cin >> l >> r;
        vec[i]->left = vec[l];
        vec[i]->right = vec[r];
        vec[i]->ch = s[i-1];
        vec[i]->exist = true;
    }

    cout << rec(vec[1]) << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
