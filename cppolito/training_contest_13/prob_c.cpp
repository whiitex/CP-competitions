#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

void rec(vector<int> v, set<ll>& res) {
    if (v.size() == 1) {
        res.insert(v[0]);
        return;
    } else {
        ll s = 0;
        int mi = INT32_MAX, ma = 0;
        bool allequ = true;
        int prev = v[0];
        for (int val: v) {
            mi = min(val, mi);
            ma = max(val, ma);
            s += val;
            if (val != prev) allequ = false;
        }
        res.insert(s);

        if (allequ) return;

        ll mid = ((ll) ma + (ll) mi) >> 1;
        vector<int> small, great;
        for (int val: v) {
            if (val <= mid) small.push_back(val);
            else great.push_back(val);
        }

        rec(small, res);
        rec(great, res);
        return;
    }

}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> vec(n);
    for (int i=0; i<n; ++i)
        cin >> vec[i];

    set<ll> res;
    rec(vec, res);

    while (q--) {
        int temp; cin >> temp;
        if (res.find(temp) != res.end())
            cout << "Yes\n";
        else cout << "No\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
