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
    int n; cin >> n;
    vector<int> vec(n);
    for (int i=0; i<n; ++i)
        cin >> vec[i];

    if (n == 1)
        cout << 0 << '\n';
    else {
        int min = vec[0], max = min;
        for (int i=0; i<n; ++i) {
            if (min > vec[i]) min = vec[i];
            if (max < vec[i]) max = vec[i];
        }
        int count = 0;
        vector<int> solvec;
        while (max!=min) {
            if (max % 2 == 0 and min % 2 == 1) {
                solvec.push_back(1);
                max = (max+1) / 2;
                min = (min+1) / 2;
            }
            else {
                solvec.push_back(0);
                max /= 2;
                min /= 2;
            }
            ++count;
        }

        cout << count << '\n';
        if (count <= n){
            for (int i=0; i<solvec.size(); ++i)
                cout << solvec[i] << ' ';
            cout << '\n';
        }
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
