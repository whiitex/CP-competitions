#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Node {
public:
    ll a;
    int i;
    Node(ll value, int index) {
        a = value;
        i = index;
    }
};

void solve(){
    ll n, c, a;
    cin >> n >> c;

    Node* vec[n];
    set<int> unconn;
    for (int i=0; i<n; i++) {
        cin >> a;
        vec[i] = new Node(a, i+1);
        unconn.insert(i);
    }

    Node* my_node = vec[0];
    unconn.erase(0);
    ll a_tot = my_node->a;
    bool masterflag = true;

    while (!unconn.empty() && masterflag) {
        bool found = false;
        for (int i : unconn) {
            if (a_tot + vec[i]->a >= vec[i]->i * c){
                unconn.erase(i);
                a_tot += vec[i]->a;
                found = true;
                break;
            }
        }
        if (!found) masterflag = false;
    }

    if (masterflag)
        cout << "YES" << '\n';
    else cout << "NO" << '\n';
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
