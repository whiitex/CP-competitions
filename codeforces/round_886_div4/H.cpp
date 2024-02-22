#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

#define x first
#define y second

void solve() {
    ll n, m; cin >> n >> m;
    vpll vec[n+1];

    for (ll i=0; i<m; ++i) {
        ll a, b, d; cin >> a >> b >> d;
        vec[a].emplace_back(b, d);
        vec[b].emplace_back(a, -d);
    }

    map<ll,ll> pos;

    ll timer = 2*m;
    while (timer) {
        ll a=1;
        while (vec[a].empty()) ++a;

        queue<ll> q; q.push(a);

        while (not vec[a].empty()) {
            ll b = vec[a].back().x, d = vec[a].back().y;
            vec[a].pop_back();

            bool isa = pos.find(a) != pos.end();
            bool isb = pos.find(b) != pos.end();
            if (not isa and not isb) {          // random insertion
                pos.insert({a, 0});
                pos.insert({b, -d});
            } else if (not isa) {               // insert according to a
                pos.insert({a, pos[b] + d});
            } else if (not isb) {               // insert according to b
                pos.insert({b, pos[a] - d});
            } else if (pos[a] - pos[b] != d) {  // check if condition is satisfied
                cout << "No\n";
                return;
            }

            --timer;
            q.push(b);

            while (vec[a].empty()) {
                q.pop();
                if (not q.empty()) a = q.front();
                else break;
            }
        }

    }

    cout << "Yes\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();

    }
}
