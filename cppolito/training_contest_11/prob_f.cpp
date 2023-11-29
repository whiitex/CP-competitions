#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

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
    float f, w, tot_sum=0;
    short n;
    cin >> f >> w >> n;
    float arr[n];
    for (int i=0; i<n; ++i) {
        cin >> arr[i];
        tot_sum += arr[i];
    }


    bool dp[1000001];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int monst=0; monst<n; monst++) {
        for (int i=tot_sum; i>=0; --i) {
            if (dp[i]) dp[i + (int)arr[monst]] = true;
        }
    }


    int res = INF;
    for (int i=0; i<=tot_sum; ++i) {
        if (dp[i]) {
            if (i==0 || i==tot_sum) {
                int n1 = ceil(tot_sum / max(f,w));
                res = min(n1, res);
            } else {
                int n1 = max(ceil(i / w), ceil((tot_sum - i) / f));
                res = min(n1, res);
            }
        }
    }

    cout << (int)res << '\n';


    /*
    // binary search
    ll l=0, r=1e7, mid;
    while (l<r) {
        mid = (l+r) >> 1;
        ll W = mid*w;
        ll F = mid*f;
        bool ok = false;
        for (int i=0; i<=tot_sum; i++) {
            if (dp[i] and W>=i and F>=(tot_sum-i)) {
                ok = true;
                break;
            }
        }


        if (ok) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';
    */

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
