#include <bits/stdc++.h>
using namespace std;

int solve_per_four(char arr[]) {
    if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3])
        return 0;
    else {
        int n = sizeof(arr) / sizeof(*arr);
        sort(arr, arr+n);

        int a = (int)arr[0];
        int b = (int)arr[1];
        int c = (int)arr[2];
        int d = (int)arr[3];

        return d*3 - a - b - c;
    }
}

void solve(){
    int n;
    cin >> n;
    char matrix[n][n];
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            cin >> matrix[i][j];

    int counter = 0;
    for (int i = 0; i< n/2; i++)
        for (int j = 0; j< n/2; j++) {
            char a = matrix[i][j];
            char b = matrix[j][n-1-i];
            char c = matrix[n-1-i][n-1-j];
            char d = matrix[n-1-j][i];

            char arr[] = {a,b,c,d};
            counter += solve_per_four(arr);
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
