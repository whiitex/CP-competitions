#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){

    int n, a=0, b=0, na=1, nb=0;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];

    bool flag = true;
    a = arr[0];
    for (int i=1; i<n; i++) {
        if (arr[i] == a)
            na++;
        else if (b==0) {
            b = arr[i];
            nb++;
        } else if (arr[i] == b)
            nb++;
        else {
            cout << "NO" << '\n';
            flag = false;
            break;
        }
    }

    if (flag) {
        if (nb == 0)
            cout << "YES" << '\n';
        else {
            if (abs(na - nb) <= 1)
                cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
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