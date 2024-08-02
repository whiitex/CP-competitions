#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

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

typedef __int128_t lll; typedef long double ld;
typedef pair<int,int> pii; typedef pair<ld,ld> pld;
typedef vector<long long> vi; typedef vector<pii> vpii;

#define pb push_back
#define f first
#define s second

const long long MAXN = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    long long n; cin >> n;
    vi vec(n); for (long long &i: vec) cin >> i;

    long long par = vec[0] % 2;
    bool is_ok = true;
    for (long long i: vec) if (i % 2 != par) is_ok = false;

    if (n == 1) {
        cout << 1 << '\n' << vec[0] << '\n';
        return;
    }

    vi ans;
    for (long long qq=0; qq<40 and is_ok; ++qq) {
        long long mn = *min_element(vec.begin(), vec.end());
        long long mx = *max_element(vec.begin(), vec.end());

        if (mn == mx and mn == 0) break;
        if (mn == 0 and mx % 2 == 1) is_ok = false;

        long long x = mn + mx >> 1;
        for (long long &i: vec) i = abs(i - x);
        ans.pb((long long)(x));
    }

    if (!is_ok) {
        cout << -1 << '\n';
    } else {

        cout << ans.size() << '\n';
        for (long long i: ans) cout << i << ' ';
        cout << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long t = 1; cin >> t;
    while (t--) solve();
}
