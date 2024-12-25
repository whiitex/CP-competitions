#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define st first
#define nd second

int parseInt (string s) {
    int ans = 0;
    for (char c: s) {
        ans *= 10;
        ans += c - '0';
    }
    return ans;
}

void solve() {
    string s = "}mul(417,770)%why(){/':mul(187,313)<@*select()mul(908,713)who()$mul(156,598)"; // ...
    int ans = 0;

    // looking for mul(abc,def)
    int ok = 1;
    for (int i=3; i<s.size(); ++i) {
        if (s.substr(i-3, 4) == "do()") {
            ok = 1; continue;
        }

        if (i > 5 and s.substr(i-6, 7) == "don't()") {
            ok = 0; continue;
        }
        if (s.substr(i-3, 4) == "mul(") {
            int j = i+1;
            while (j < s.size() and s[j] != ',') ++j;
            if (j == i+1 or j > i+4) continue;
            int a = parseInt(s.substr(i+1, j-i-1));
            int k = j+1;
            while (k < s.size() and s[k] != ')') ++k;
            if (k == j+1 or k > j+4) continue;
            int b = parseInt(s.substr(j+1, k-j-1));
            if (ok) ans += a*b;
            i = k-1;
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}




















































