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
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;
    vi check;

    for (int i = 0; i < n - 1; ++i) {
        if (vec[i] == 0) check.pb(0);
        else if (vec[i] > vec[i + 1]) {
            vi toadd;
            while (vec[i]) {
                toadd.pb(vec[i] % 10);
                vec[i] /= 10;
            }
            std::reverse(toadd.begin(), toadd.end());
            for (int q: toadd) check.pb(q);
        } else {
            vi toadd;
            int vi = vec[i];
            while (vi) {
                toadd.pb(vi % 10);
                vi /= 10;
            }
            if (!check.empty()) toadd.pb(*check.rbegin());
            std::reverse(toadd.begin(), toadd.end());

            bool ok = true;
            for (int j=0; j<toadd.size()-1; ++j) {
                if (toadd[j] > toadd[j+1]) ok = false;
            }

            if (ok) {
                for (int j=(int)(!check.empty()); j<toadd.size(); ++j) check.pb(toadd[j]);
            } else check.pb(vec[i]);
        }
    }
    check.pb(vec[n-1]);

    for (int i=0; i<check.size()-1; ++i) {
        if (check[i] > check[i+1]) {
            cout << "No\n"; return;
        }
    }

    cout << "Yes\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}
