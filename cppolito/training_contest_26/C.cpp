#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

vi get_seq(int aa, int bb) {
    int a = min(aa, bb);
    int b = max(aa, bb);
    int B = b;
    while (__builtin_clz(B) < __builtin_clz(a)) B >>= 1;

    vi seq;
    while (B != a) {
        seq.pb(a / 2);
        a >>= 1;
        B >>= 1;
    }

    vi seq_rev;
    while (b != a) {
        seq_rev.pb(b);
        b >>= 1;
    }

    std::reverse(seq_rev.begin(), seq_rev.end());
    if (!seq_rev.empty()) seq_rev.pop_back();

    if (!seq_rev.empty()) for (int i: seq_rev) seq.pb(i);
    if (aa > bb) std::reverse(seq.begin(), seq.end());
    return seq;
}

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    if (std::count(vec.begin(), vec.end(), -1) == n) {
        for (int i=1; i<n; i+=2)
            cout << "2 1 ";
        if (n & 1) cout << 2;
        cout << '\n';
        return;
    }


    // left -1
    int i = 0;
    while (i < n and vec[i] == -1) ++i;

    for (int j=i-1; j>=0; j-=2) {
        if (j > 0) vec[j-1] = vec[j+1];
        vec[j] = vec[j+1] * 2;
    }

    // right -1
    int k = n-1;
    while (vec[k] == -1) --k;

    for (int j=k+1; j<n; j+=2) {
        if (j < n-1) vec[j+1] = vec[j-1];
        vec[j] = vec[j-1] * 2;
    }


    for (; i<k;) {
        int start = vec[i];
        int j = i+1;
        while (vec[j] == -1) ++j;
        int end = vec[j];

        int positions = j - i - 1;

        // adjacent known numbers
        if (positions == 0) {
            if (vec[i] / 2 != vec[j] and vec[j] / 2 != vec[i]) {
                cout << -1 << '\n';
                return;
            } else {
                i = j;
                continue;
            }
        }

        // numbers separated by -1 * 'positions'
        if (start != end) {
            vi seq = get_seq(start, end);
            int seqsize = seq.empty() ? 0 : seq.size();
            if (seqsize > positions or (positions - seqsize) & 1) {
                cout << -1 << '\n';
                return;
            }

            for (int k = 0; k < seqsize; ++k) {
                vec[i + k + 1] = seq[k];
            }

            for (int k = i + seqsize + 1; k < j; k += 2) {
                if (k + 1 < j) vec[k + 1] = vec[k - 1];
                vec[k] = vec[k - 1] * 2;
            }
        } else {
            if (positions % 2 == 0) {
                cout << -1 << '\n';
                return;
            }
            for (int k=i+1; k<j; k+=2) {
                if (k < j-1) vec[k+1] = vec[k-1];
                vec[k] = vec[k-1] * 2;
            }
        }

        i = j;
    }

    for (int iq: vec) cout << iq << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
