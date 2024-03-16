#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;

#define pb push_back
#define f first
#define s second

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); for (int &i: a) cin >> i;
    vi b(n); for (int &i: b) cin >> i;

    vi ans1, ans2;
    int a1=0, a2=0;
    map<int,int> mp1, mp2;

    for (int i: a) mp1[i]++;
    for (int i: b) mp2[i]++;

    auto f = [&] (map<int,int> &mp, int &a, vi &an) -> void {
        for(pii p: mp) {
            if (p.s == 2) {
                an.pb(p.f);
                an.pb(p.f);
                ++a;
                if (a == k) return;
            }
        }
    };

    f(mp1, a1, ans1);
    f(mp2, a2, ans2);

    if (a1 != k) {
        k = (k-a1) * 2;
        for (pii p: mp1) {
            if (p.s == 1) {
                ans1.pb(p.f);
                ans2.pb(p.f);
                ++a1;
                if (a1 == k) break;
            }
        }
    }

    for (int i: ans1) cout << i << ' ';
    cout << '\n';
    for (int i: ans2) cout << i << ' ';
    cout << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
