#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;


// Ordered set - increasing order
template<typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
// .find_by_order( k ) -> iterator 0-based of k-th largest element (0 = smallest)
// .order_of_key( k ) -> how many items in the set are < k

// Ordered set - reversed
template<typename T>
using ordered_set_gre = __gnu_pbds::tree<T, __gnu_pbds::null_type, greater<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
// .find_by_order( k ) -> iterator 0-based of k-th smallest element (0 = great)
// .order_of_key( k ) -> how many items in the set are > k

typedef __int128_t lll; typedef long long ll; typedef long double ld;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef vector<int> vi; typedef vector<ll> vll; typedef vector<pii> vpii; typedef vector<pll> vpll;

#define pb push_back
#define f first
#define s second

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

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
    int n; cin >> n;
    vector<int> a(n);
    vector<ll> sum(n);
    vpii coup(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        if (i == 0) sum[0] = a[i];
        else sum[i] = sum[i - 1] + a[i];
        if (i == 0) coup[0] = {a[i] % 2 == 0, a[i] % 2 == 1};
        else {
            coup[i] = coup[i-1];
            if (a[i]%2 == 0) coup[i].f++;
            else coup[i].s++;
        }
    }


    for (int k=0; k<n; ++k) {
        if (k == 0) cout << a[k] << ' ';
        else {
            ll ans = sum[k];
            int disp = coup[k].s, pari = coup[k].f;
            if (disp % 3 == 0) ans -= disp/3;
            else if (disp % 3 == 1) {
                ans -= (disp + 2) / 3;
            } else {
                ans -= disp/3;
            }
            cout << ans << ' ';
        }
    }

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
