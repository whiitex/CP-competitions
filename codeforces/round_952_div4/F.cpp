#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define f first
#define s second

const int INF = 1e13;

void solve() {
    int h, n; cin >> h >> n;
    vpii a(n);
    for (pii &i: a) cin >> i.f;
    for (pii &i: a) cin >> i.s;

    int l = 1, r = INF;
    while (l < r) {
        int mid = l + r >> 1;

        int damage = 0;
        for (pii i: a) {
            damage += i.f * ((mid - 1) / i.s + 1);
            if (damage >= h) break;
        }

        if (damage >= h) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
