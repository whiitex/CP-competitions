#include <bits/stdc++.h>

using namespace std;

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


void solve() {
    string s; cin >> s;
    int n = (int) s.length();
    int q; cin >> q;

    vector<int> pref(n);
    int mlen = 0;
    for (int i = 1; i < n; ++i) {
        while (mlen > 0 and s[mlen] != s[i])
            mlen = pref[mlen - 1];

        if (s[mlen] == s[i]) ++mlen;
        pref[i] = mlen;
    }

    unordered_map<string, pii> memo; // mlen, pref
    vi newpref(10);
    while (q--) {
        string t; cin >> t;
        int tn = (int)t.size();

        int MLEN = mlen;
        string st;
        for (int i = 0; i < tn; ++i) {
            st.pb(t[i]);
            if (memo.find(st) != memo.end()) {
                pii p = memo[st];
                MLEN = p.f; newpref[i] = p.s;
                continue;
            }
            while (MLEN > 0 and (MLEN < n ? s[MLEN] : t[MLEN-n]) != t[i])
                MLEN = (MLEN-1 < n ? pref[MLEN - 1] : newpref[MLEN-1-n]);

            if ((MLEN < n ? s[MLEN] : t[MLEN-n]) == t[i]) ++MLEN;
            newpref[i] = MLEN;
            if (i < 8) memo[st] = {MLEN, newpref[i]};
        }

        for (int i = 0; i < tn; ++i) cout << newpref[i] << ' ';
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();
}
