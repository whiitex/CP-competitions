#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define pb push_back

const int INF = 1e18;

void solve() {
    int A, B, C;
    string p;

    cin >> p >> p >> A;
    cin >> p >> p >> B;
    cin >> p >> p >> C;
    cin >> p >> p; p.pb(',');

    int a=0, b=0, c=0;
    auto combo = [&] (int val) -> int {
        if (val == 4) return a;
        if (val == 5) return b;
        if (val == 6) return c;
        if (val == 7) { cout << "Invalid combo: " << val << '\n'; return -1; }
        return val;
    };

    auto dv = [&] (int val) -> int {
        int num = a, exp = combo(val);
        // int bits = 32 - __builtin_clz(num);
        //
        // if (exp > bits) return 0;
        return num / (int)pow(2, exp);
    };
    cout << p << '\n' << '\n';

    vi ans;
    auto f = [&] (auto f, int index, int A) -> void {
        // if (index > (int)p.size()) { ans.pb(A); return; }
        if (index < 0) { ans.pb(A); return; }

        string out;
        for (int add= (index == p.size()-2 ? 1 : 0); add<8; ++add) {
            out = "";
            int AA = a = A + add * (int)pow(2,(index/2 * 3));
            // a += (int)pow(2,index/2 * 3 + 3);
            b = 0, c = 0;

            int ip=0;
            while (ip < (int)p.size()) {
                int opcode = p[ip] - '0'; ip+=2;
                int val = p[ip] - '0'; ip+=2;

                switch (opcode) {
                case 0: a = dv(val); break;
                case 1: b = b ^ val; break;
                case 2: b = combo(val) % 8; break;
                case 3: if (a != 0) ip = val * 2; break;
                case 4: b = b ^ c; break;
                case 5:
                    out.pb(char(combo(val) % 8 + '0'));
                    out.pb(','); break;
                case 6: b = dv(val); break;
                case 7: c = dv(val); break;
                default: cout << "Invalid opcode: " << opcode << '\n'; return;
                }
            }

            if (out[index] == p[index]) {
                // cout << out << '\n';
                f(f, index-2, AA);
            }
        }
    };

    f(f, p.size()-2, 0);
    for (int i: ans) cout << i << ' ';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

/*
Register A: 30878003
Register B: 0
Register C: 0
Program: 2,4,1,2,7,5,0,3,4,7,1,7,5,5,3,0

b = (a % 8) xor 2
c = a / 2^b
a /= 8
b = b xor c xor 7
out.pb(b % 8)
 */
