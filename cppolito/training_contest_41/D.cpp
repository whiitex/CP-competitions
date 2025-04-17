#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;
#define pb push_back

struct Node {
    int value = 0, cntstart, cntend, len;
    char start, end;
    Node() {};
    Node(int l, char s, char e): len(l), start(s), end(e) {};
};

int hashstr(string s) {
    int h = 0, mul = 1;
    for (char c: s) {
        h += mul * (c - 'a' + 1);
        mul *= 30;
    } return h;
}

void solve() {
    map<int,Node> mp;
    int n; cin >> n; while (n--) {
        string var, op; cin >> var >> op;

        if (op == ":=") {
            string s; cin >> s;
            Node node(s.size(), s[0], s.back());
            if (s[0] == 'h' or s[0] == 'a') {
                char exp = s[0]; int st = 0;
                for (; st<s.size(); ++st) {
                    if (s[st] != exp) break;
                    exp = exp == 'h' ? 'a' : 'h';
                }
                node.cntstart = st;
            }

            if (s.back() == 'h' or s.back() == 'a') {
                char exp = s.back(); int en = 0;
                for (; en<s.size(); ++en) {
                    if (s[s.size()-1-en] != exp) break;
                    exp = exp == 'h' ? 'a' : 'h';
                }
                node.cntend = en;
            }

            int v = 0;
            if (s.size() >= 4 and s.substr(0, 4) == "haha") ++v;
            if (s.size() == 5 and s.substr(1, 4) == "haha") ++v;
            node.value = v;

            mp[hashstr(var)] = node;
        } else if (op == "=") {
            string lvar, rvar; cin >> lvar >> rvar >> rvar;
            Node l = mp[hashstr(lvar)], r = mp[hashstr(rvar)];
            Node newnode(l.len + r.len, l.start, r.end);
            newnode.cntend = r.cntend; newnode.cntstart = l.cntstart;

            int totvalue = l.value + r.value;
            if (l.end == 'a' and r.start == 'h') {
                totvalue -= max(0ll, l.cntend / 2 - 1) + max(0ll, r.cntstart / 2 - 1);
                int totlen = l.cntend + r.cntstart - (l.cntend & 1) - (r.cntstart & 1);
                totvalue += max(0ll, totlen / 2 - 1);

                if (l.cntend == l.len) newnode.cntstart = l.len + r.cntstart;
                if (r.cntstart == r.len) newnode.cntend = r.len + l.cntend;
            } else if (l.end == 'h' and r.start == 'a') {
                totvalue -= max(0ll, (l.cntend-1) / 2 - 1) + max(0ll, (r.cntstart-1) / 2 - 1);
                int totlen = l.cntend + r.cntstart - (l.cntend % 2 == 0) - (r.cntstart % 2 == 0);
                totvalue += max(0ll, totlen / 2 - 1);

                if (l.cntend == l.len) newnode.cntstart = l.len + r.cntstart;
                if (r.cntstart == r.len) newnode.cntend = r.len + l.cntend;
            }

            newnode.value = totvalue;
            mp[hashstr(var)] = newnode;
        }

        if (!n) cout << mp[hashstr(var)].value << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}