#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;
\
#define pb push_back

const int INF = 1e18;

void solve() {
    // int n = 32; // test
    int n = 3380; // puzzle
    map<string, set<string>> adj;
    for (int i=0; i<n; ++i) {
        string u, v; char c;
        cin >> c; u.pb(c); cin >> c; u.pb(c);
        cin >> c >> c; v.pb(c); cin >> c; v.pb(c);
        adj[u].insert(v);
        adj[v].insert(u);
    }

    int ans1 = 0;
    set<string> done;
    for (auto [in, st]: adj) if (in[0] == 't') {
        for (string sec: st) if(!done.contains(sec)) {
            for (string th: adj[sec]) {
                if (!done.contains(th) and adj[th].contains(in))
                    ++ans1;
            }
        } done.insert(in);
    }
    cout << "part 1: " << ans1/2 << '\n';


    vector<string> ans2;
    for (auto [in, st]: adj) {
        for (int MASK = 1; MASK < 1<<st.size(); ++MASK) {
            vector<string> candidate = {in};
            int mask = MASK;
            for (const string& u: st) {
                if (mask & 1) candidate.pb(u);
                mask >>= 1;
            }

            // check
            bool ok = true;
            for (const string& u: candidate) {
                for (const string& v: candidate) {
                    if (u != v and !adj[u].contains(v)) {
                        ok = false; break;
                    }
                }
            }

            if (ok and candidate.size() > ans2.size()) ans2 = candidate;
        }
    }

    sort(ans2.begin(), ans2.end());
    cout << "part 2: ";
    for (string s: ans2) {
        cout << s;
        if (s != *ans2.rbegin()) cout << ',';
    } cout << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}






















