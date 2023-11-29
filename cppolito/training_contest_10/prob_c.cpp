#include <bits/stdc++.h>
using namespace std;

string update_string(string str, int l, int r) {
    char tochange = str[l];
    for (int i = l+1; i<r; i++)
        str[i] = tochange;
    return str;
}

void solve(){
    string up, down;
    cin >> up >> down;
    unsigned short i = 1;
    int len = up.length();

    bool flag = true;
    bool opt = true;

    while(i < len-1 && flag && opt){
        if(up[i] == '1' && down[i] == '1') opt = false;

        if(up[i] != down[i]) {
            bool flag2 = true;
            int L, R;

            // CERCA VALORI CORNICE UGUALI PER FARE IL CAMBIO
            for (int l = i-1; l >= 0 && flag2; l--)
                for (int r = i+1; r < len-1 && flag2; r++)
                    if (up[l] == up[r] && down[l] == down[r] && up[l] == down[l]) {
                        flag2 = false;
                        L = l;
                        R = r;
                    }

            if (!flag2) {
                up = update_string(up, L, R);
                down = update_string(down, L, R);
                i = R+1;
            } else flag = false;

        } else i++;

    }

    cout << (flag ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    unsigned short t;
    cin >> t;

    while(t--){
        solve();
    }
}

