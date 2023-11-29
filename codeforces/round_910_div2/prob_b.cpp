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

void solve() {

    //input
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; ++i)
        cin >> arr[i];

    if (n == 1) {
        cout << 0 << '\n';
    } else {

        ll res = 0, i = n - 2;

        while (i >= 0) {
            if (arr[i] > arr[i+1]) {
                res += ceil((double)arr[i] / (double)arr[i+1]) - 1;
                arr[i] = floor(arr[i] / ceil((double)arr[i] / (double)arr[i+1]));
            }
            --i;
        }

        cout << res << '\n';

        /*
        while (i >= 0) {
            if (arr[i] <= arr[i+1])
                --i;
            else {
                if ((arr[i]+1) / 2 > arr[i+1]) {
                    res += ceil((double)arr[i] / (double)arr[i+1]) - 1;
                    arr[i] = (arr[i] - arr[i+1] * (ceil((double)arr[i] / (double)arr[i+1]) - 2))/2;
                    --i;
                }
                else {
                    int temp = arr[i];
                    arr[i] = arr[i] / 2;
                    arr[i+1] = temp - arr[i];
                    ++res;
                }

            }
        }
        cout << res << '\n';

         */
    }

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
