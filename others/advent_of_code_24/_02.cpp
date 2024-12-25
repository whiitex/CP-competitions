#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define st first
#define nd second

vi parseLine(const std::string& line) {
    vi result;
    std::istringstream lineStream(line);
    int number;

    while (lineStream >> number) {
        result.push_back(number);
    }
    return result;
}

void solve() {

    vector<string> g = {
        "72 74 75 77 80 81 81",
        "52 53 55 58 59 63",
        "14 17 19 22 27",
        "65 68 67 68 71 73 76 77",
        "53 56 53 55 54",
        "60 62 59 62 62",
        // ...
    };
    int ans = 0;
    for (string s: g) {
        vi v = parseLine(s);

        if (v.size() == 1) { ++ans; continue; }


        auto check = [&] (vi& v) -> int {
            int cre = v[1] > v[0];
            for (int i=1; i<v.size(); ++i) {
                if (cre != (int)(v[i] > v[i-1])) {return i-1;}
                if (abs(v[i] - v[i-1]) < 1 or abs(v[i] - v[i-1]) > 3) {return i-1;}
                if (i == v.size()-1) ++ans;
            }
            return -1;
        };

        int rep = check(v);
        if (rep > -1) {
            vi v1; for (int i=0; i<v.size(); ++i) if (i != rep) v1.push_back(v[i]);
            vi v2; for (int i=0; i<v.size(); ++i) if (i != rep+1) v2.push_back(v[i]);

            rep = check(v1);
            if (rep != -1) check(v2);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}




















































