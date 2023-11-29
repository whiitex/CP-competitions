#include <bits/stdc++.h>
using namespace std;

void solve(){

    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c)
        cout << "YES" << '\n';
    else {
        int arr[3] = {a, b, c};
        int n = sizeof(arr) / sizeof(arr[0]);
        sort(arr, arr + n);

        // caso due uguali
        if (arr[0] == arr[1]) {
            if (arr[2] % arr[0] == 0 && arr[2] / arr[0] < 5)
                cout << "YES" << '\n';
            else cout << "NO" << '\n';
        } else if (arr[2] % arr[0] == 0 && arr[1] % arr[0] == 0 && (arr[2] / arr[0] + arr[1] / arr[0]) < 6) {
            cout << "YES" << '\n';
        } else cout << "NO" << '\n';
    }
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
