#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n = 4;
    char arr[n+1];
    arr[0] = '1';
    for (int i = 1; i<n+1; i++)
        cin >> arr[i];

    int sol = 0;
    for (int i = 0; i<n; i++) {
        if (arr[i] == '0' && arr[i+1] == '0')
            sol = sol;
        else if (arr[i] == '0')
            sol += abs('9' - arr[i + 1]) + 1;
        else if (arr[i + 1] == '0')
            sol += abs(arr[i] - '9' ) + 1;

        else sol += abs(arr[i] - arr[i + 1]);
    }
    cout << sol + 4 << '\n';
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
