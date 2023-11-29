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


/* TIME LIMIT EXCEEDED1
 *
int rec1(char c, int left, int right, string s) {

    // base condition: analizing last 1-item partition
    if (left + 1 == right) {
        if (s[left] == c) return 0;
        else return 1;

    } else {
        // count higher value of char c
        int cl=0, cr=0, mid = (left + right) >> 1;
        for (int i=left; i<right;++i) {
            if (s[i] == c and i<mid) ++cl;
            else if (s[i] == c and i>=mid) ++cr;
        }

        if (cl != cr)
            return mid-left + min(rec(c+1, mid, right, s) -cl, rec(c+1, left, mid, s) -cr);
        else
            return mid-left-cl + min(rec(c+1, mid, right, s), rec(c+1, left, mid, s));
    }
}
 */


/* TIME LIMIT EXCEEDED 2
 *
int rec2(char c, int left, int right, string s, vector<vector<int>> DP, int size) {

    // base condition: analizing last 1-item partition
    if (left + 1 == right) {
        if (s[left] == c) return 0;
        else return 1;

    } else {
        // count higher value of char c
        int base = c-'a';
        if (base == size-1) --base;
        int pts = (int)pow(2, base+1);
        int mid = (left + right) >> 1;
        int pos = (int)( (float)left/(float)s.size() * (float)pts );
        int cl = DP[c-'a'][pos];
        int cr = DP[c-'a'][pos+1];

        return mid-left + min(rec(c+1, mid, right, s, DP, size) -cl,
                              rec(c+1, left, mid, s, DP, size) -cr);
    }
}
 */

void solve() {
    int n;
    string str;
    cin >> n >> str;

    if (n == 1) {
        if (str[0] == 'a')
            cout << 0 << '\n';
        else cout << 1 << '\n';
    } else {
        int size = (int) log2(n) + 1;

        // init dp vector
        vector<vector<int>> dp(size);
        for (int i = 0; i < size; ++i) {
            if (i < size - 1) {
                vector<int> useless_pointer((int) pow(2, i + 1), 0);
                dp[i] = useless_pointer;
            } else { // last vec has same size of previous one
                vector<int> useless_pointer((int) pow(2, i), 0);
                dp[i] = useless_pointer;
            }
        }

        // fill dp vector O(d * 2^d)
        for (int i = 0; i < n; ++i) {
            int base = str[i] - 'a';
            if (base == size - 1) --base; // last vec has same size of previous
            if (base <= size - 1) {
                int pts = (int) pow(2, base + 1);
                int pos = i / (n / pts);
                ++dp[str[i] - 'a'][pos];
            }
        }

        // properly sum elements of last two vectors
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0)
                dp[size - 2][i] += dp[size - 1][i + 1];
            else dp[size - 2][i] += dp[size - 1][i - 1];
        }

        // properly sum elements of vectors from '1' to 'size-1'
        for (int i = 0; i < size - 2; ++i) {
            for (int j = 0; j < dp[i].size(); ++j) {
                if (j % 2 == 0) {
                    dp[i + 1][2 * (j + 1)] += dp[i][j];
                    dp[i + 1][2 * (j + 1) + 1] += dp[i][j];
                } else {
                    dp[i + 1][2 * (j - 1)] += dp[i][j];
                    dp[i + 1][2 * (j - 1) + 1] += dp[i][j];
                }
            }
        }

        int mas = 0;
        for (int v: dp[size - 2])
            if (mas < v) mas = v;

        cout << n - mas << '\n';
    }

//    int sol = rec1('a', 0, n, str)
//    int sol = rec2('a', 0, n, str, dp, size);
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
