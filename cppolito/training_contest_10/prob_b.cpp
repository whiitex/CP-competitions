#include <bits/stdc++.h>
using namespace std;

void solve(){
    short len = 10;
    short sum = 0;
    string arr[len];
    for (size_t i = 0; i<len; i++){
        cin >> arr[i];
    }


    for (size_t i = 0; i<len; i++){
        for (size_t k = 0; k<5; k++){
            if ( i >= k && i <= len-k-1 && arr[i][k] == 'X') { sum += k+1; }
            if ( i >= k && i <= len-k-1 && arr[i][len-k-1] == 'X') { sum += k+1; }
            if ( i >= k+1 && i <= len-k-2 && arr[k][i] == 'X') { sum += k+1; }
            if ( i >= k+1 && i <= len-k-2 && arr[len-k-1][i] == 'X') { sum += k+1; }
        }
    }


    cout << sum << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
