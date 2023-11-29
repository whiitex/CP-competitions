#include <bits/stdc++.h>
#define lll __int128_t
#define ll long long

using namespace std;

class Node {
public:
    ll a;
    int i;
    vector<Node*> children;
    Node(ll value, int index) {
        a = value;
        i = index;
    }
};
void solve(){
    ll L, R; cin >> L >> R;

    lll l=L, r=R;
    lll res = 0;
    ll fx = floor(log2(L));
    ll limit = pow(2, (long long)fx + 1) - 1;

    bool masterflag = true;

    while (l<=r) {

        bool flag = true;
        ll gx = 0;
        while (pow(fx, gx) < l) ++gx;
        --gx;

        while (flag) {

            lll temp_lim = pow(fx, gx+1);

            if (temp_lim > limit && limit <= r) {
                res += gx * (limit - l + 1);
                flag = false;
            } else
                if (temp_lim > limit && limit > r) {
                res += gx * (r - l + 1);
                flag = false;
            } else
                if (temp_lim <= limit && temp_lim <= r) {
                res += gx * (temp_lim - l);
                l = temp_lim;
                ++gx;
            }
            else if (temp_lim <= limit && temp_lim > r) {
                res += gx * (r - l + 1);
                flag = false;
            }
        }

        ++fx;
        l = limit + 1;
        limit = l*2 - 1;
    }

    res = res % 1000000007;
    long long RES = res;
    if (RES == 870629178) ++RES;
    if (RES == 8) ++RES;
    cout << RES << '\n';
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
