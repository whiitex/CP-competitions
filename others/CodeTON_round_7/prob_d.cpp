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
    ll a;
    int i;
    vector<Node*> children;
    Node(ll value, int index) {
        a = value;
        i = index;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> vec(n);
    for (int i=0; i<n; ++i)
        cin >> vec[i];

    int op, s, i, v;
    for (int z=0; z<q; ++z) {
        cin >> op;

        if (op == 2) {
            cin >> i >> v;
            vec[i-1] = v;
        } else
            if (op == 1) {
            cin >> s;
            int l=0, k=0, sum = 0;
            while (k<n and sum != s) {
                sum += vec[k];
                if (sum > s) {
                    sum -= vec[l];
                    ++l;
                } else if (sum == s)
                    break;
                ++k;
            }
            if (sum == s)
                cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
    }

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
