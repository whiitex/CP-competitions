#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        int tota = (int)std::count(s.begin(), s.end(), 'A');
        if (std::count(s.begin(), s.end(),'B') == 0 or tota == 0) {
            cout << 0 << '\n';
            continue;
        }
        int n = (int)s.length();

        if (s[0] == 'B' or s[n-1] == 'B') {
            cout << tota << '\n';
        } else {
            bool consb = false;
            for (int i=0; i<n-1; ++i) if (s[i] == 'B' and s[i+1] == 'B') consb = true;
            if (consb) {
                cout << tota << '\n';
            } else {
                vi as;
                for (int i=0; i<n;) {
                    int a=0, b=0, l=i;
                    while (s[i] == 'A') ++i;
                    a = i-l; l = i;
                    as.push_back(a);
                    while (s[i] == 'B') ++i;
                }
                std::sort(as.begin(), as.end());
                cout << tota - as[0] << '\n';
            }
        }

    }
}
