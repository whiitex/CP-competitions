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
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr+n);
    bool two = false;
    for (int i=0; i<n-1; ++i) {
        if ( abs(arr[i] - arr[i+1]) == 1 ) {
            two = true;
            break;
            }
    }
    if (two) cout << 2 << '\n';
    else cout << 1 << '\n';
    /*
    int lines = 0;

    vector<int> mat[100];
    memset(mat, 0, sizeof(mat));
    for (int i=0; i<n; ++i) {

        bool newline = true;
        for (int j=0; j<lines; j++) {
            bool flag = true;
            for (int val: mat[j]) {
                if (abs(arr[i] - val) == 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                mat[j].push_back(arr[i]);
                newline = false;
                break;
            }
        }
        if (newline) {
            mat[lines].push_back(arr[i]);
            ++lines;
        }

        if (lines == 2) break;

    }

    cout << lines << '\n';
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
