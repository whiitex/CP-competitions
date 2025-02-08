#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define st first
#define nd second

const int MAXN = 5e5 + 5;
const int MOD = 1e9+7;
const int INF = 1e18;

void solve() {
    string s, t; cin >> s >> t;
    int n = (int)s.size();

    vpii svec(n);
    for (int i=0; i<n; ++i) {
        svec[i].st = s[i] == '1' ? 1 : -1;
        int j = i + 1;
        while (j < n and s[j] == s[i]) ++j;
        svec[i].nd = j - i;
        i = j - 1;
    }

    int ans = 0;
    int pos, num, qt;
    for (int i=0; i<n; ++i) {
        if (svec[i].st != 0) {
            pos = i, num = svec[i].st, qt = svec[i].nd;
        }

        if (num == -1) num = 0;
        if (t[i] - '0' == num) continue;

        if (i != pos or i + qt >= n) { cout << -1 << '\n'; return; }

        int newnum = svec[i+qt].st;
        int newqt = svec[i+qt].nd;
        svec[i+qt] = {0, 0};

        svec[i + newqt] = {num == 0 ? -1 : 1, qt};

        if (pos + qt + newqt < n) {
            svec[i + newqt].nd += svec[pos + qt + newqt].nd;
            svec[pos + qt + newqt] = {0, 0};
        }

        num = newnum, qt = newqt;
        ++ans;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
