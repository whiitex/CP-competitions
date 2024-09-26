#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define pb push_back
#define f first
#define s second

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n; cin >> n;
    int digits = n < 10 ? 1 : n < 100 ? 2 : 3;

    vpii ans;
    for (int a=1; a<=10000; ++a) {
        int numa = n * a;
        int lim = 0;
        {
            int NUMA = numa;
            while (NUMA) {
                NUMA /= 10; ++lim;
            }
        }

        for (int rem=1; rem <= min(10000ll, min(numa, lim)); ++rem) {

            int b = a * digits - rem;
            if (b == 0) continue;

            int target = n * a - b;
            int check = 0;

            if (digits == 1) {
                for (int _=0; _<rem; ++_) {
                    check *= 10; check += n;
                }
            } else if (digits == 2) {
                for (int _=1; _<rem; _+=2) {
                    check *= 100; check += n;
                }
                if (rem % 2) {
                    check *= 10; check += n/10;
                }
            } else if (digits == 3) {
                for (int _=2; _<rem; _+=3) {
                    check *= 1000; check += n;
                }
                if (rem % 3 == 1) {
                    check *= 10; check += n/100;
                } else if (rem % 3 == 2) {
                    check *= 100; check += n/10;
                }
            }

            if (check == target) ans.pb({a, b});
        }
    }

    cout << ans.size() << '\n';
    if (!ans.empty()) for (pii i: ans) cout << i.f << ' ' << i.s << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
