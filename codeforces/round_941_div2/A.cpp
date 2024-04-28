#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back
#define f first
#define s second

void solve() {
    int n, k; cin >> n >> k;
    vi vec(n); for (int &i: vec) cin >> i;

    map<int,int> mp;
    for (int i: vec) ++mp[i];
    vi vecs;
    for (auto p: mp) vecs.pb(p.s);
    std::sort(vecs.begin(), vecs.end(), greater());

    int more = 0;
    int ans = 0;
    for (int i: vecs) {
        if (i >= k) more += i / k;
        else if (!more) ans += i;
    }

    cout << (ans == 0 ? k-1 : ans) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}
