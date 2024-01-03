#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n, q;
    cin >> n >> q;

    vector<int> a(n), query;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<q; i++) {
        int temp; cin >> temp;
        if (i == 0) query.push_back(temp);
        else if (temp < *query.rbegin())
            query.push_back(temp);
    }

    for (int el: a) {
        for (int two: query)
            if (el % (1 << two) == 0)
                el += (1 << (two - 1));
        cout << el << ' ';
    }
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}
