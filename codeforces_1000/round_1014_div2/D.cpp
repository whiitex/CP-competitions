#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

int notx(int a, int b) {
    int x = 0; while (x == a or x == b) ++x;
    return x;
}

vi ins(vi& a, int pos) {
    vi ret = a;
    int x = notx(a[pos], a[pos+1]);
    ret.insert(ret.begin() + pos + 1, x);
    return ret;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vi a(n); for (int i=0; i<n; ++i) {
        a[i] = s[i] == 'T' ? 0 : s[i] == 'I' ?  1 : 2;
    }
    vi tot(3); for (int i: a) ++tot[i];

    int allsame = 1; for (int i=1; i<n; ++i) allsame += a[i] == a[0];
    if (allsame == n) { cout << -1 << '\n'; return; }

    int mn = min({tot[0], tot[1], tot[2]});
    vi left(3); for (int i=0; i<3; ++i) left[i] = tot[i] - mn;

    vi ans;
    while (1) {

        int done = 0;
        for (int i=0; i<a.size()-1; ++i) if (a[i] != a[i+1]) {
            if (left[a[i]]) {
                --left[a[i]];
                a = ins(a, i); a = ins(a, i);
                ans.pb(i+1); ans.pb(i+1);
                done = 1; break;
            }

            if (left[a[i+1]]) {
                --left[a[i+1]];
                a = ins(a, i); a = ins(a, i+1);
                ans.pb(i+1); ans.pb(i+2);
                done = 1; break;
            }
        }

        if (max({left[0], left[1], left[2]}) == 0) {
            cout << ans.size() << '\n';
            for (int i: ans) cout << i << ' ';
            cout << '\n'; return;
        }
        if (!done) { cout << -1 << '\n'; return; }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
