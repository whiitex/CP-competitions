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

#define int long long
typedef __int128_t lll; typedef long double ld;
typedef pair<int,int> pii; typedef pair<ld,ld> pld;
typedef vector<int> vi; typedef vector<pii> vpii;

#define pb push_back
#define f first
#define s second

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n; cin >> n; --n;
    vi b(n); for (int &i: b) cin >> i;

    vi a; a.pb(b[0]);
    for (int i=0; i<n; ++i) {
        int to_pb = 0;
        for (int bit = 0; bit < 30; ++bit) {
            int two = int(1 << bit);

            if ((a[i] & two) == 0) {
                if (i < n-1 and (b[i+1] & two)) to_pb += two;
            } else if (b[i] & two) to_pb += two;
        }

        a.pb(to_pb);
    }

    // check
    bool is_ok = true;
    for(int i=0; i<n; ++i) {
        int ck = (a[i] & a[i+1]);
        if (ck != b[i]) is_ok = false;
    }
    if (is_ok) {
        for (int i: a) cout << i << ' ';
    } else cout << -1;

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
