#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q; cin >> q;
    multiset<int> left, right;

    while (q--) {
        int l, r;
        char sign;
        cin >> sign >> l >> r;

        if (sign == '+')
            left.insert(l), right.insert(r);
        else
            left.erase(left.find(l)), right.erase(right.find(r));

        if (!left.empty()) {
            int maxl = *left.rbegin();
            int minr = *right.begin();
            cout << (maxl > minr ? "YES\n" : "NO\n");
        } else cout << "NO\n";
    }
}
