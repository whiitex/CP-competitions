#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define x first
#define y second

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        map<int,int> height, width, vert, oriz;
        vector<pii> vec(n);

        ll ans = 0;
        for (int i=0; i<n; ++i) {

            // computation
            cin >> vec[i].x >> vec[i].y;
            ans += height[vec[i].y];
            ans += width[vec[i].x];
            ans += vert[vec[i].y - vec[i].x];
            ans += oriz[vec[i].y + vec[i].x];

            // preparation
            height[vec[i].y]++;
            width[vec[i].x]++;
            vert[vec[i].y - vec[i].x]++;
            oriz[vec[i].y + vec[i].x]++;
        }

        cout << 2*ans << '\n';
    }
}
