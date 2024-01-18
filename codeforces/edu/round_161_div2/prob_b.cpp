#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;


struct Node {
    ll a;
    int i;
    vector<Node*> children;
    Node(ll value, int index) {
        a = value;
        i = index;
    }
};

void solve() {
    int n, t; cin >> n;
    vi vec(n);
    for(int i=0; i<n; ++i) {
        cin >> t;
        vec[i] = t;
    }
    std::sort(vec.begin(), vec.end());

    if (n < 3) {
        cout << 0 << '\n';
        return;
    }
    ll ans = 0, tot=0, ck=1;
    int now = vec[0];
    for(int i=1; i<n; ++i) {
        while (i<n and vec[i] == now) {
            ++i; ++ck;
        }

        if (ck > 2) {
            ans += ck * (ck - 1) * (ck - 2) / 6;
            ans += tot * ck * (ck - 1) / 2;
        }
        else if (ck == 2)
            ans += tot;

        tot += ck;
        ck = 1;
        now = vec[i];
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
