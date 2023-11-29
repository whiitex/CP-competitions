#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, a, counter = 0;
    cin >> n;
    cin >> a;

    int rem = a % 2;
    while(--n) {
        cin >> a;
        if (a % 2 == rem)
            counter++;
        else rem = a % 2;
    }
    cout << counter << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
