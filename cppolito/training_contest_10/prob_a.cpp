#include <bits/stdc++.h>

#define endline '\n'

using namespace std;

void solve(){
    bool flag;
    string str;
    cin >> str;

    if (str[0] == 'a' || str[1] == 'b' || str[2] == 'c') {
        flag = true;
    } else flag = false;
    cout << (flag ? "YES" : "NO") << endline;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

