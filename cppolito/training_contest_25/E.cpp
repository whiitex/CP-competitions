#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, trash; cin >> n;

    if (n == 2) {
        cout << "! 1 2 2 1" << endl;
        cin >> trash;
        return;
    }

    cout << "+ " << n+1 << endl;
    cin >> trash;
    cout << "+ " << n+2 << endl;
    cin >> trash;

    int mx = -1, end1;
    for (int i=2; i<=n; ++i) {
        cout << "? 1 " << i << endl;
        cin >> trash;
        if (trash > mx) {
            end1 = i;
            mx = trash;
        }
    }

    vi ans1(n+1); ans1[end1] = 1;
    int END = n/2+1;
    vi ans2(n+1); ans2[end1] = END;
    for (int i=1; i<=n; ++i) {

        if (i != end1) {
            cout << "? " << end1 << ' ' << i << endl;
            cin >> trash;

            // end1
            if (trash & 1) ans1[i] = n - trash/2;
            else ans1[i] = 1 + trash/2;

            // end2
            if (n % 2 == 0) {
                if (trash & 1) ans2[i] = END - (trash / 2 + 1);
                else ans2[i] = END + trash/2;
            } else {
                if (trash & 1) ans2[i] = END + (trash / 2 + 1);
                else ans2[i] = END - trash/2;
            }
        }

    }

    cout << "! ";
    for (int i=1; i<=n; ++i) cout << ans1[i] << ' ';
    for (int i=1; i<=n; ++i) cout << ans2[i] << ' ';
    cout << endl;
    cin >> trash;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
