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
    int n, a, b;
    string s;
    cin >> n;
    cin >> s;
    for ( int i=0; i<n; i++) {
        if (s[i] == 'a') ++a;
        else ++b;
    }

    bool flag = true;
    for (int i=0; i<n and flag; i++) {
        for (int j=n-1; j>=i+1; j--) {

            a = 0; b = 0;
            for (int x=i; x<=j; ++x) {
                if (s[x] == 'a') ++a;
                else ++b;
            }
            if (a == b){
                flag = false;
                cout << ++i << ' ' << ++j << '\n';
                break;
            }

        }
    }
    if (flag) cout << -1 << ' ' << -1 << '\n';

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
