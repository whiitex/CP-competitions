#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {
    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> a(n);
    vector<int> b(n), A(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
        A[i] = a[i].first;
    }
    for (int i=0; i<n; ++i)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> sol(n);

    for (int i=0; i<x; ++i) {
        sol[ a[n-x+i].second ] = b[i];
    }

    for (int i=0; i<n-x; ++i) {
        sol[ a[i].second ] = b[x+i];
    }

    // check
    int count = 0;
    for (int i=0; i<n; ++i) {
        if (A[i] > sol[i])
            ++count;
    }

    if (count == x) {
        cout << "YES\n";
        for (int i: sol)
            cout << i << ' ';
        cout << '\n';
    } else cout << "NO\n";




}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
