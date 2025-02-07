#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;
    vi b(n); for (int &i: b) cin >> i;

    map<int,int> A,B;
    for (int i: a) A[i]++;
    for (int i: b) B[i]++;

    int cnta = 0, cntb = 0;
    for (auto [i,j]: A) cnta++;
    for (auto [i,j]: B) cntb++;

    if ((cnta >= 2 and cntb >= 2) or (cnta >= 3 or cntb >= 3)) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
