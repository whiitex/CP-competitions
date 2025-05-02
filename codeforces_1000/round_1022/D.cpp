#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int ask(int i) {
    cout << "? " << i << endl;
    int x; cin >> x; return x;
}

void answer(int a, int b) {
    cout << "! " << a;
    if (a != -1) cout << " " << b;
    cout << endl;
}

void solve() {
    int n, k; cin >> n >> k;
    if (n == 2 * k) { answer(k, k); return; }
    if (k == 1 and n > 2*k) { answer(-1, -1); return; }

    vi a(k); for (int i=1; i<=k; ++i) a[i%k] = ask(i);
    vi b(k); for (int i=n-k+1; i<=n; ++i) b[i%k] = ask(i);
    vi same(k); for (int i=0; i<k; ++i) same[i] = a[i] == b[i];

    int cnt = 0; for (int i=0; i<k; ++i) cnt += a[i] == b[i];
    if (cnt == k) { answer(-1, -1); return; }

    int l = k+1, r = n-k+1;
    while (l < r) {
        int m = l + r >> 1;

        while (same[m%k] and m >= l) --m;
        if (m < l) {
            ++m;
            while (same[m%k] and m <= r) ++m, ++l;
        }

        if (ask(m) != a[m%k]) r = m;
        else l = m + 1;
    }

    int lena = l-1, lenb = n-l+1;

    if (lenb > k and same[(lena+1) % k]) answer(-1, -1);
    if (lena > k and same[(lena) % k]) answer(-1, -1);
    else answer(lena, lenb);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
