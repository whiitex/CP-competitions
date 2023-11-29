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

int check(int arr[], int x, int n) {
    int count = 0;
    for (int i=0; i<n; ++i) {
        if (arr[i] <= x) ++count;
    }

    return count;
}

void solve(){

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    int arr[n];
    for (int i=0; i<n; ++i)
        cin >> arr[i];

    int l=1, r = 1e9, mid;
    while (l<r) {
        mid = (l+r) >> 1;
        int ck = check(arr, mid, n);
        if (ck == t) {
            r = 0;
            l = mid;
        } else if (ck > t) {
            r = mid;
        } else l = mid + 1;

    }

    if (check(arr, l, n) == t)
        cout << l << '\n';
    else cout << -1 << '\n';
}
