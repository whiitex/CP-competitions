#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n; cin >> n;
    vector<int> vec(n);
    for (int i=0; i<n; ++i) cin >> vec[i];

    vector<bool> exist(256,false);
    exist[0] = true;
    int ans = 0, curr = 0;
    for (int val: vec) {
        curr = curr ^ val;
        for (int i=0; i<256; ++i) {
            if (exist[i]) {
                ans = max(ans, i ^ curr);
                //exist[curr ^ i] = true;
            }
        }
        exist[curr] = true;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
