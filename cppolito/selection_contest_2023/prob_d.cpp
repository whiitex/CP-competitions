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



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    string s;
    cin >> n >> t;
    cin >> s;
    int i=0;

    if (n == 1 and t > 0)
        s = '0';
    else {
        while (t > 0 and i < n) {
            if (i == 0) {
                if (s[0] != '1') {
                    --t;
                    s[0] = '1';
                }
            } else {
                if (s[i] != '0') {
                    --t;
                    s[i] = '0';
                }
            }

            ++i;
        }
    }

    cout << s << '\n';
}
