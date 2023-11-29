#include <bits/stdc++.h>
using namespace std;

long long triangle_upper_slice(long long n, long long b) {
    return (b+n) * (n-b+1) / 2;
}

long long triangle_lower_slice(long long b) {
    return (b+1) * b / 2;
}

void solve(){
    long long n, x, y;
    cin >> n >> x >> y;

    if (x == n && x == y)
        cout << 0 << '\n';
    else {
        // number of dividers
        long long num_div_x = n/x;
        long long num_div_y = n/y;
    //    cout << "num_div x and y:" << '\n';
    //    cout << num_div_x << '\n';
    //    cout << num_div_y << '\n';

        // number of common dividers
        long long mcm = x*y/__gcd(x,y); //MCM(x,y);
        long long num_same_div = floor(n/mcm);

        // number of different dividers
        long long diff_x = num_div_x - num_same_div;
        long long diff_y = num_div_y - num_same_div;
    //    cout << "diff_x and diff_y:" << '\n';
    //    cout << diff_x << '\n';
    //    cout << diff_y << '\n';

        // final calculus
        long long positive = 0;
        long long negative = 0;
        if (diff_x) positive = triangle_upper_slice(n, n-diff_x+1);
        if (diff_y) negative = triangle_lower_slice(diff_y);

    //    cout << "pos and neg: " << '\n';
    //    cout << positive << '\n';
    //    cout << negative << '\n';
        cout << positive - negative << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
