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
    int n, k; cin >> n >> k;
    ll prod = 1;
    for (int i=0; i<n; ++i) {
        int l; cin >> l;
        prod *= l;
    }

    ll test = 2023 / prod;
    if (prod > 2023 or test * prod != 2023 )
        cout << "NO\n";
    else {
        cout << "YES\n";
        cout << 2023/prod << ' ';
        for (int i=0; i<k-1; ++i) cout << 1 << ' ';
        cout << '\n';
    }


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
