#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

// ORDERED SET - TREE
template<typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
// .find_by_order( k ) -> iterator 0-based of k-th largest element
// .order_of_key( k ) -> how many items in the set are < k

#define lll __int128_t
#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    ll n, t1, t2; cin >> n;
    ordered_set<ll> myset;

    vector<pair<ll,ll>> arcs(n);
    for (int i=0; i<n; ++i) {
        cin >> t1; cin >> t2;
        arcs[i] = {t2,t1};
    }

    std::sort(arcs.begin(), arcs.end(), greater());

    ll ans = 0;
    for (auto arc: arcs) {
        ans += myset.order_of_key(arc.second);
        myset.insert(arc.second); // insert starting point
    }

    cout << ans << '\n';
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
