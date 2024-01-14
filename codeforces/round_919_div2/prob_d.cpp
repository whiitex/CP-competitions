#include <bits/stdc++.h>

using namespace std;

typedef __int128_t lll; typedef long long ll;
typedef pair<ll,ll> pll; typedef vector<pll> vpll;
#define f first
#define s second

void solve() {
    ll n, q; cin >> n >> q;
    lll nowLen = 1;
    map<lll, ll> m;
    vpll chunk;
    for (ll i=0; i<n; ++i) {
        ll b, x; cin >> b >> x;
        if (b == 1 and nowLen <= (ll)1e18) {
            m.insert({nowLen, x});
            ++nowLen;
        } else if (nowLen <= (ll)1e18) {
            chunk.emplace_back(nowLen-1, x+1);
            nowLen = nowLen + (nowLen-1)*x;
        }
    }

    for (ll i=0; i<q; ++i) {
        ll pos; cin >> pos;
        ll k = (ll)chunk.size()-1;
        while ((ll)chunk.size() > 0 and chunk[k].f+1 > pos) --k;

        while (k>=0) {
            ll cf = chunk[k].f;
            ll cs = chunk[k].s;
            lll prod = (lll) cs * (lll) cf;

            if (m.find(pos) != m.end()) break;

            if (pos >= cf + 1 and pos <= (ll) min((lll) 1e18, prod)) {
                ll div = pos / cf;
                pos = pos - div * cf;
                if (pos == 0) pos = cf;
            }
            --k;
        }
        cout << m[pos] << ' ';
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while (t--) {
        solve();
    }
}

/*
1
9 20
1 1
1 2
2 1
1 3
2 1
1 4
2 1
1 5
2 2
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

expected output:
1 2 1 2 3 1 2 1 2 3 4 1 2 1 2 3 1 2 1 2
*/

/*
1
10 31
1 1
1 2
2 2
1 3
1 4
2 2
1 5
1 6
2 1
1 7
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 53

expected output:
1 2 1 2 1 2 3 4 1 2 1 2 1 2 3 4 1 2 1 2 1 2 3 4 5 6 1 2 1 2 7
*/