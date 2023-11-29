#include <bits/stdc++.h>
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
    int n, m=32;
    cin >> n;
    int arr[n+1];
    arr[0] = -1000000;
    for (int i=1; i<n+1; i++)
        cin >> arr[i];

    bool flag = true;
    while (flag && m>2) {
        for (int i=m/2+1; i< min(m, n); i++)
            if (arr[i] > arr[i+1]) {
                flag = false;
                break;
            }
        m/=2;
    }

    cout << (flag ? "Yes" : "No") << '\n';

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
