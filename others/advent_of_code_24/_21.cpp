#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

const int INF = 1e18;

void solve() {
    vector<string> codes = {"805A","170A","129A","283A","540A"}; // puzzle
    // vector<string> codes = {"029A","980A","179A","456A","379A"}; // test
    // vector<string> codes = {"029A/"}; // test
    // vector<string> codes = {"0"}; // test

    unordered_map<char, pii> keypad = {
        {'A', {0,0}}, {'3', {1,0}}, {'6', {2,0}}, {'9', {3,0}},
        {'0', {0,1}}, {'2', {1,1}}, {'5', {2,1}}, {'8', {3,1}},
                      {'1', {1,2}}, {'4', {2,2}}, {'7', {3,2}}
    };

    unordered_map<char, pii> dirpad = {
        {'>', {0,0}}, {'A', {1,0}},
        {'v', {0,1}}, {'^', {1,1}},
        {'<', {0,2}}
    };

    auto gen_numeric_keypad = [&] (string& code) -> string {
        int x = 0, y = 0;
        string ans;
        for (char c: code) {
            auto [xx, yy] = keypad[c];

            if (yy <= y) {
                if (xx == 0 and y == 2) {
                    for (int i=0; i<y-yy; ++i) ans.pb('>');
                    for (int i=0; i< abs(xx-x); ++i)
                        ans.pb(xx > x ? '^' : 'v');
                } else {
                    for (int i=0; i< abs(xx-x); ++i)
                        ans.pb(xx > x ? '^' : 'v');
                    for (int i=0; i<y-yy; ++i) ans.pb('>');
                }
            } else {
                if (x == 0 and yy == 2) {
                    for (int i=0; i< abs(xx-x); ++i)
                        ans.pb(xx > x ? '^' : 'v');
                    for (int i=0; i<yy-y; ++i) ans.pb('<');
                } else {
                    for (int i=0; i<yy-y; ++i) ans.pb('<');
                    for (int i=0; i< abs(xx-x); ++i)
                        ans.pb(xx > x ? '^' : 'v');
                }
            }

            ans.pb('A');
            x = xx, y = yy;
        } return ans;
    };

    auto gen_directional_keypad = [&] (string& code) -> string {
        int x = 1, y = 0;
        string ans;
        for (char c: code) {
            auto [xx, yy] = dirpad[c];

            if (yy <= y) {
                if (xx == 1 and y == 2) {
                    for (int i=0; i<y-yy; ++i) ans.pb('>');
                    if (xx != x) ans.pb(xx > x ? '^' : 'v');
                } else {
                    if (xx != x) ans.pb(xx > x ? '^' : 'v');
                    for (int i=0; i<y-yy; ++i) ans.pb('>');
                }
            } else {
                if (x == 1 and yy == 2) {
                    if (xx != x) ans.pb(xx > x ? '^' : 'v');
                    for (int i=0; i<yy-y; ++i) ans.pb('<');
                } else {
                    for (int i=0; i<yy-y; ++i) ans.pb('<');
                    if (xx != x) ans.pb(xx > x ? '^' : 'v');
                }
            }

            ans.pb('A');
            x = xx, y = yy;
        } return ans;
    };

    auto idx = [&] (char c) -> int {
        switch (c) {
            case '>': return 0;
            case 'A': return 1;
            case 'v': return 2;
            case '^': return 3;
            case '<': return 4;
            default: return 1000;
        }
    };

    int dp[5][5][30];
    for (int i=0; i<5; ++i) for (int j=0; j<5; ++j) for (int k=0; k<30; ++k) dp[i][j][k] = 0;
    for (int i=0; i<5; ++i) for (int j=0; j<5; ++j) dp[i][j][1] = 1;
    for (int i=2; i<30; ++i) {
        for (char c: "<>^vA") if (c != 0) {
            for (char g: "<>^vA") if (g != 0) {

                string code; code.pb(g); code.pb(c); // gc
                string gen_code = gen_directional_keypad(code);
                int index = 0; while (gen_code[index] != 'A') ++index; ++index;

                int idc = idx(c), idg = idx(g);

                for (; index < (int)gen_code.size(); ++index) {
                    // if (gen_code[index] == gen_code[index-1]) ++dp[idc][idg][i];
                    // else dp[idc][idg][i] += dp[idc][idx()]
                    dp[idc][idg][i] += dp[idx(gen_code[index])][idx(gen_code[index-1])][i-1];
                }

            }
        }
    }

    int ans = 0, ROBOTS = 25;
    for (string& code: codes) {
        string gen_pad = gen_numeric_keypad(code);
        // for (int i=0; i<ROBOTS; ++i) {
            // cout << i << ' ' << gen_pad.size() << endl;
            // cout << gen_pad << endl;
            // gen_pad = gen_directional_keypad(gen_pad);
        // }
        int len = 0;
        for (int i=0; i< (int)gen_pad.size(); ++i) {
            if (i == 0) len += dp[idx(gen_pad[0])][idx('A')][ROBOTS+1];
            else len += dp[idx(gen_pad[i])][idx(gen_pad[i-1])][ROBOTS+1];
        }

        // ans += (int)gen_pad.size() * stoi(code.substr(0,3));
        // cout << len << endl;
        ans += len * stoi(code.substr(0,3));
    }

    cout << ans << endl;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}
