#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Node {
public:
    ll a;
    ll i;
    vector<Node*> children;
    Node(ll value, ll index) {
        a = value;
        i = index;
    }
};

void solve(){
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);

    ll last=n, x=0, tot=0;
    for (ll i=0; i<last; i++) {
        if (i == last-1) {
            if (arr[i] == 1) tot += 1;
            else tot += (arr[i] - x + 1) /2 + 1;
        }
        else if (x < arr[last-1]) {
            if (arr[i] + x < arr[last-1]) {
                tot += arr[i];
                x += arr[i];
            } else {
                tot += arr[last-1] - x + 1;
                arr[i] -= arr[last-1] - x;
                x = 0;
                --last;
                if (arr[i] > 0) --i;
            }
        }

    }

    cout << tot << '\n';

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
