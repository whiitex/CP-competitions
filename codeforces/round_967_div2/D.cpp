#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

const int INF = 1e9;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    set<int> st;
    unordered_map<int,int> mp;
    for (int i=0; i<n; ++i) {
        st.insert(vec[i]);
        ++mp[vec[i]];
    }

    int mxlen = st.size();
    cout << mxlen << '\n';

    bool firstbig = true;
    vi ans;
    deque<int> chosen;
    set<int> stchosen;
    unordered_map<int,int> freq;
    for (int i: vec) {
        if (!st.contains(i)) continue;

        chosen.pb(i);
        stchosen.insert(i);
        ++freq[i];

        if (mp[i] == 1) {
            int val = 0;
            while (val != i) {
                val = firstbig ? *stchosen.rbegin() : *stchosen.begin();
                ans.pb(val);

                stchosen.erase(val);
                st.erase(val);
                firstbig = !firstbig;

                while (!chosen.empty() and chosen.front() != val) {
                    --freq[chosen.front()];
                    if (freq[chosen.front()] == 0) stchosen.erase(chosen.front());
                   chosen.pop_front();
                }

                chosen.pop_front();
            }
        }

        --mp[i];
    }

    for (int i: ans) cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
