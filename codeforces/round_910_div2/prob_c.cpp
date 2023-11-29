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
    int n,m,k;
    cin >> n >> m >> k;
    if (k > n+m-2) {
        if ((k - (n + m - 2)) % 4 == 0)
            k -= k - (n + m - 2);
        else k -= k - (n + m - 2) - (k-(n+m-2))%4;
    }

    if (k == n+m-2 or k == n+m) {

        char arr1[n][m-1];
        memset(arr1, 'R', sizeof(arr1));

        // upper orizontal path
        for (int i = 1; i < m-1; ++i) {
            if (arr1[0][i - 1] == 'R')
                arr1[0][i] = 'B';
            else arr1[0][i] = 'R';
        }

        char arr2[n-1][m];
        memset(arr2, 'R', sizeof(arr2));

        // starting color of right vertical path
        if (arr1[0][m-2] == 'R')
            arr2[0][m-1] = 'B';
        else arr2[0][m-1] = 'R';

        // right vertical path
        for (int i=1; i<n-1; ++i){
            if (arr2[i - 1][m-1] == 'R')
                arr2[i][m-1] = 'B';
            else arr2[i][m-1] = 'R';
        }

        // for loop in upper left square
        arr2[0][0] = 'B';
        arr2[0][1] = 'B';


        if (arr2[n-3][m-1] == 'R')
            arr1[n-2][m-2] = 'B';
        else arr1[n-2][m-2] = 'R';
        arr1[n-1][m-2] = arr1[n-2][m-2];
        arr2[n-2][m-2] = arr2[n-3][m-1];


        // printing solution
        cout << "YES" << '\n';
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m-1; ++j)
                cout << arr1[i][j] << ' ';
            cout << '\n';
        }
        for (int i = 0; i < n-1; ++i) {
            for (int j = 0; j < m; ++j)
                cout << arr2[i][j] << ' ';
            cout << '\n';
        }

    } else cout << "NO" << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}
