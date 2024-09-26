#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

// Ordered set - increasing order
template<typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
// .find_by_order( k ) -> iterator 0-based of k-th largest element (0 = smallest)
// .order_of_key( k ) -> how many items in the set are < k

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define f first
#define s second


void solve() {
    int n; cin >> n;
    vpii vec(n);
    vi VEC(n); for (int &i: VEC) cin >> i;
    for (int i=0; i<n; ++i) {
        vec[i].f = VEC[i];
        vec[i].s = i;
    }

    sort(vec.begin(), vec.end(), [](pii a, pii b) {
        if (a.f == b.f) return a.s < b.s;
        return a.f > b.f;
    });

    int m; cin >> m;
    vector<array<int, 3>> quests(m);
    for (int i=0; i<m; ++i) {
        cin >> quests[i][0] >> quests[i][1];
        quests[i][2] = i;
    }

    sort(quests.begin(), quests.end());


    ordered_set<int> os;
    int i = 0;

    vi ans(m);
    for (auto q: quests) {
        int k = q[0], pos = q[1];

        while (i < k) {
            os.insert(vec[i].s);
            ++i;
        }

        int ind = *os.find_by_order(pos -1);
        ans[q[2]] = VEC[ind];
    }

    for (int a: ans) cout << a << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();
}
