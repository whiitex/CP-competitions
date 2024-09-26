#include <bits/stdc++.h>

using namespace std;

#define int long long

#define f first
#define s second

void solve() {
    string s; cin >> s;
    int index, n = s.size(); cin >> index;

    int rem = n;
    while (index > rem) {
        index -= rem;
        --rem;
    }

    priority_queue<pair<char,int>> pq;
    int nowsize = n;
    for (int i=0; i<n and nowsize > rem; ++i) {

        while (!pq.empty() and pq.top().f > s[i] and nowsize > rem) {
            s[-pq.top().s] = 'X';
            --nowsize;
            pq.pop();
        }

        pq.push({s[i], -i});
    }

    while (nowsize > rem) {
        s[-pq.top().s] = 'X';
        pq.pop();
        --nowsize;
    }

    int i = 0; --index;
    while (index) {
        if (s[i] != 'X') --index;
        ++i;
    }

    while (s[i] == 'X') ++i;

    cout << s[i];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
