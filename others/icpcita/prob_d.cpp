#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

bool ispal(string s) {
    for (int i=0; i<s.length()/2; ++i)
        if (s[i] != s[s.length()-i-1])
            return false;
    return true;
}

void solve() {

    // init
    ll n; cin >> n;
    vector<string> vec(n);
    for (int i=0; i<n; ++i)
        cin >> vec[i];

    // preprocessing
    // let's consider each string as to be attached AFTER
    // the one that will be considered in solving part
    // so map receives all possible string able to build
    // a palindrome one
    map<string,int> m;
    for (const string& str: vec) {
        for (int i=0; i<str.length(); ++i) {
            if (ispal(str.substr(0,i))) {
                string rev = str.substr(i, str.length());
                std::reverse(rev.begin(), rev.end());
                if (m.find(rev) != m.end())
                    m[rev]++;
                else m.insert({rev, 1});
            }
        }
    }

    // solve
    ll sol = 0;
    for (const string& str: vec) {

        // look in map
        if (m.find(str) != m.end()) {

            // avoid self-concatenation
            if (ispal(str)) sol += m[str] - 1;
            else sol += m[str];
        }
    }

    cout << sol;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
//    cin >> t;
    while (t--) {
        solve();
    }
}
