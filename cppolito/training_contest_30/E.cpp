#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define pb push_back

const int INF = 1e9;

void solve() {
    int n; cin >> n;

    if (n == 1) {
        cout << "! 1" << endl; return;
    }

    vi ans(n+1);
    int mxpos, mnpos, val;
    char c;

    function ask = [&] (int i) -> char {
        cout << "? " << i << endl;
        char t; cin >> t;
        if (t == '>') ++val;
        else if (t == '<') --val;
        return t;
    };

    // find max
    val = 0; int mxval = -INF;
    for (int i=1; i<=n; ++i) {
        do {
            c = ask(i);
            if (val > mxval) {
                mxval = val; mxpos = i;
            }
        } while (c == '>');
    }

    // find min
    val = 0; int mnval = INF;
    for (int i=1; i<=n; ++i) {
        do {
            c = ask(i);
            if (val < mnval) {
                mnval = val; mnpos = i;
            }
        } while (c == '<');
    }

    ans[mnpos] = 1; ans[mxpos] = n;
    do c = ask(mxpos);
    while (c == '>');

    int x = n;

    function setx = [&] (int value) -> void {
        int rep = abs(value - x);
        if (value > x) while (rep--) ask(mxpos);
        else while (rep--) ask(mnpos);
        x = value;
    };

    // vector of request to be done on the target arr[0]
    // binary search solution over all positions
    vector<vector<array<int,3>>> requests(n+1, vector<array<int,3>>());
    for (int i=1; i<=n; ++i) if (i != mnpos and i != mxpos) requests[n + 1 >> 1].pb({i, 1, n});

    for (int i=0; i<30; ++i) {
        for (int targ= i%2 ? 1 : n; ; targ += i%2 ? 1 : -1) {
            if (targ == 0 or targ == n+1) break;

            while (!requests[targ].empty()) {
                auto arr = *requests[targ].rbegin();
                int pos = arr[0], l = arr[1], r = arr[2];
                requests[targ].pop_back();

                setx(targ);
                c = ask(pos);

                if (c == '=') ans[pos] = targ;
                else {
                    if (c == '>') l = targ + 1, ++x;
                    else r = targ - 1, --x;

                    if (l == r) ans[pos] = l;
                    else requests[l + r >> 1].pb({pos, l, r});
                }
            }
        }
    }

    // final answer
    cout << "! "; for (int i=1; i<=n; ++i) cout << ans[i] << ' '; cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
