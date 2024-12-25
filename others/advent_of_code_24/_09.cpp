#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

int count(int id, int pos, int len) {
    int ans = 0;
    for (int i=pos; i<pos+len; ++i) ans += id * i;
    return ans;
}

void solve() {
    string s; cin >> s;
    int n = s.size();

    int pos = s[0] - '0';
    s = s.substr(1, n-1);

    int id = 1, f = 1;
    set<array<int,3>> free, file;
    for (int i=0; i<(int)s.size(); ++i) {
        if (f) {
            if (s[i] - '0') free.insert({pos, s[i] - '0', 0});
        }
        else {
            file.insert({-pos, s[i] - '0', id});
            ++id;
        }

        pos += s[i] - '0';
        f ^= 1;
    }

    set<array<int,3>> compactdisk;
    for (auto [p, len, id]: file) {
        int fp = -1, flen = -1;
        for (auto [fp_, flen_, _]: free) {
            if (fp_ > -p) break;
            if (flen_ < len) continue;

            fp = fp_; flen = flen_; break;
        }

        if (fp == -1) compactdisk.insert({-p, len, id});
        else {
            free.erase({fp, flen, 0});
            if (flen - len > 0) free.insert({fp+len, flen - len, 0});
            compactdisk.insert({fp, len, id});
        }
    }

    int ans = 0;
    for (auto [p, len, id]: compactdisk) ans += count(id, p, len);

    // vi disk;
    // int free = 1, id = 1;
    // for (int i=0; i<n; ++i) {
    //     for (int j=0; j<s[i] - '0'; ++j) {
    //         if (free) disk.pb(-1);
    //         else disk.pb(id);
    //     }
    //
    //     if (!free) ++id;
    //     free ^= 1;
    // }
    //
    // int ans = 0, r = (int)disk.size()-1;
    // for (int i=0; i<=r; ++i) {
    //     if (disk[i] != -1) ans += disk[i] * (i + off);
    //     else {
    //         while (r > i and disk[r] == -1) --r;
    //         if (r >= i) {
    //             ans += disk[r] * (i + off);
    //             --r;
    //         }
    //     }
    // }

    cout << ans << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}


