#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int MAXN = 2e5 + 5;

vector<int> Upar(MAXN);
vector<int> Usz(MAXN);

int Ufind(int node) {
    if (Upar[node] == node) return node;
    return Upar[node] = Ufind(Upar[node]);
}

void Umerge(int a, int b) {
    a = Ufind(a), b = Ufind(b);
    if (a == b) return;
    if (Usz[a] < Usz[b]) swap(a, b);
    Upar[b] = a; Usz[a] += Usz[b];
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i=1; i<=n; ++i) Upar[i] = i;

    vector dp(n+1, vi(11));
    while (m--) {
        int a, d, k; cin >> a >> d >> k;
        ++dp[a][d]; --dp[a + k*d][d];
    }

    for (int d=1; d<=10; ++d) for (int i=1; i<=n; ++i) {
        if (i > d) dp[i][d] += dp[i-d][d];
    }

    for (int i=1; i<=n; ++i) for (int d=1; d<=10; ++d) {
        if (i > d and dp[i-d][d] > 0) Umerge(i, i-d);
    }

    int ans = 0;
    set<int> st;
    for (int i=1; i<=n; ++i) {
        int p = Ufind(i);
        if (!st.contains(p)) {
            ++ans; st.insert(p);
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
