#include <bits/stdc++.h>

using namespace std;


#define int long long
typedef long double ld;
typedef pair<ld,ld> pld;

#define pb push_back
#define f first
#define s second

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ld EPS = 1e-9;

ld dist(pld x, pld y) {
    ld xx = x.f - y.f;
    ld yy = x.s - y.s;
    return sqrt(xx * xx + yy * yy);
}

void solve() {
    pld P, A, B;
    cin >> P.f >> P.s;
    cin >> A.f >> A.s;
    cin >> B.f >> B.s;

    if (dist(A,{0,0}) > dist(B,{0,0})) swap(A, B);

    ld ans = dist({0,0}, A);
    if (dist(A,P) > ans) {
        ld trA = dist(A, P);
        ld trB = max(dist(A,B)/2, dist(B,P));
        ans = max(ans, min(trA, trB));
    }

    cout << setprecision(9) << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}
