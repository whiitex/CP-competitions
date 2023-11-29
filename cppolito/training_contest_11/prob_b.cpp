#include <bits/stdc++.h>

using namespace std;

bool check(long long n) {
    long long temp = n;
    bool div = true;
    while (temp > 0) {
        long long c = temp % 10;
        if (c != 0 && n % c != 0) {
            div = false;
            break;
        }
        temp /= 10;
    }
    return div;

}

void solve(){
    string s;
    cin >> s;

    long long n = atoll(s.c_str());

    while(!check(n))
        n++;
    cout << n << '\n';
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
