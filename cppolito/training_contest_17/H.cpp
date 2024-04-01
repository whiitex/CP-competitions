#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;


void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    vi str(n);      // <1, >0
    for (ll i=0; i<n; ++i) {
        str[i] = (s[i] == '<' ? 1 : 0);
    }

    vll ans1, ans2;

    int k=0;
    ll dx = 0;
    deque<ll> sx;

    auto f = [&] (vll &ans) {

        while (k<n and str[k]) {
            ans.push_back(k+1);
            ++k;
        }

        for (int i=k; i<n; ++i) {

            if (not str[i]) {      // -->

                ++dx;
                while (k < n-1 and sx.size() < dx) {
                    ++k;
                    if (str[k]) sx.push_back(k);
                }

                if (k >= n-1 and sx.size() < dx) return;

                if (i == 0) ans.push_back(2*sx[0] + 1);
                else ans.push_back(*ans.rbegin() + 2*(k-i) + 1);


            } else if (str[i]) {   // <--

                sx.pop_front();
                while (k < n-1 and sx.size() < dx) {
                    ++k;
                    if (str[k]) sx.push_back(k);
                }

                if (k >= n-1 and sx.size() < dx) break;

                if (i == 0) ans.push_back(1);
                else ans.push_back(*ans.rbegin() + (k-i)*2 + 1);
            }

        }
    };


    f(ans1);

    k = 0; dx = 0; sx.clear();
    std::reverse(str.begin(), str.end());
    for (int& i: str) i = (i ? 0 : 1);
    f(ans2);

    std::reverse(ans2.begin(), ans2.end());

    for (ll i: ans1) cout << i << ' ';
    for (ll i: ans2) cout << i << ' ';
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
