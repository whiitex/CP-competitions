#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define f first
#define s second

int solve() {
    string s; cin >> s;
    int n = s.length();

    int one = 0, zero = 0;
    for (char c: s) {
        if (c == '1') ++one;
        else ++zero;
    }

    if (one == n or zero == n) return 0;

    vpii pref(n), suff(n);
    {
        int z = 0, o = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') ++o;
            else ++z;
            pref[i] = {z, o};
        }

        z = s[n-1] == '0', o = s[n-1] == '1';
        for (int i=n-2; i>=0; --i) {
            suff[i] = {z, o};
            if (s[i] == '1') ++o;
            else ++z;
        }
    }

    int ans = (int)(1e12 + 1) * (min(zero, one));
    for (int i=0; i<n; ++i) {
        bool sw = 0;
        if (i < n-1 and s[i] == '1' and s[i+1] == '0') sw = 1;

        int newans = (int)(1e12+1) * (pref[i].s - sw);
        newans += (int)(1e12+1) * (suff[i].f - sw);

        if (sw) newans += (int)(1e12);
        ans = min(ans, newans);
    }

    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) cout << solve() << '\n';
}

