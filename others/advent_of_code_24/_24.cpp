#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

unordered_map<string, int> part1(int n, int m, auto wire, auto done, auto adj, int print=0) {
    queue<array<string,4>> que;
    for (auto const& [w1, vec]: adj) {
        vector<array<string,4>> to_erase;
        for (auto arr: vec) {
            if (done[w1] and done[arr[0]]) {
                to_erase.pb({w1, arr[0], arr[1], arr[2]});
                que.push({w1, arr[0], arr[1], arr[2]});
            }
        }

        for (auto arr: to_erase) { // clean
            adj[w1].erase({arr[1], arr[2], arr[3]});
            adj[arr[0]].erase({w1, arr[2], arr[3]});
        }
    }

    while (!que.empty()) {
        auto [w1, w2, op, res] = que.front(); que.pop();

        if (op == "AND") wire[res] = wire[w1] & wire[w2];
        if (op == "OR") wire[res] = wire[w1] | wire[w2];
        if (op == "XOR") wire[res] = wire[w1] ^ wire[w2];
        ++done[res];

        vector<array<string,4>> to_erase;
        for (auto arr: adj[res]) {
            if (done[arr[0]]) {
                que.push({res, arr[0], arr[1], arr[2]});
                to_erase.pb({res, arr[0], arr[1], arr[2]});
            }
        }

        for (auto arr: to_erase) { // clean
            adj[w1].erase({arr[1], arr[2], arr[3]});
            adj[arr[0]].erase({w1, arr[2], arr[3]});
        }
    }

    map<string, int> vec_ans1;
    for (const auto& [w, val]: wire) {
        if (w[0] == 'z') vec_ans1[w] = val;
    }

    int ans = 0, pos = 0;
    for (const auto&  [_, bit]: vec_ans1) {
        ans += bit * (int)pow(2, pos);
        ++pos;
    }
    if (print) cout << "part 1: " << ans << '\n';

    return wire;
}

auto part2 (int n, int m, auto wire, auto done, auto adj, auto got, auto back) {
    vi correct(46); int bonus = 0;
    for (int i=0; i<46; ++i) {
        string code = to_string(i);
        if (code.size() == 1) code = "0" + code;
        int val = bonus + wire["x" + code] + wire["y" + code];
        correct[i] = val % 2;
        bonus = val > 1;
    }

    auto check = [&] (unordered_map<string, int>& mp) -> bool {
        for (int i=0; i<46; ++i) {
            string code = to_string(i);
            if (correct[i] != mp["z" + code]) return false;
        } return true;
    };

    set<string> involved; int wrong = 0;
    for (int i=0; i<46; ++i) { // insert all involved strings to be swapped
        string code = to_string(i);
        if (code.size() == 1) code = "0" + code;
        string z = "z" + code;
        if (correct[i] != got[z]) {
            ++wrong;
            queue<string> que; que.push(z);
            while (!que.empty()) {
                string w = que.front(); que.pop();
                if (w[0] != 'x' and w[0] != 'y') {
                    involved.insert(w);
                    que.push(back[w][0]);
                    que.push(back[w][1]);
                }
            }
        }
    }

    cout << involved.size() << '\n';
    cout << wrong << '\n';
}


void solve() {
    int n = 90; // puzzle
    // int n = 10; // test 1
    unordered_map<string, int> done, wire;
    for (int i=0; i<n; ++i) {
        string w; cin >> w;
        int val; cin >> val;
        wire[w] = val; ++done[w];
    }

    int m = 222; // puzzle
    // int m = 36; // test 1
    unordered_map<string, set<array<string,3>>> adj;
    unordered_map<string, array<string,2>> back;
    for (int i=0; i<m; ++i) {
        string w1, op, w2, res;
        cin >> w1 >> op >> w2 >> res >> res;
        adj[w1].insert({w2, op, res});
        adj[w2].insert({w1, op, res});
        back[res] = {w1, w2};
    }

    auto got = part1(n, m, wire, done, adj, 1);

    vi correct(46); int bonus = 0;
    for (int i=0; i<46; ++i) {
        string code = to_string(i);
        if (code.size() == 1) code = "0" + code;
        int val = bonus + wire["x" + code] + wire["y" + code];
        correct[i] = val % 2;
        bonus = val > 1;
        if (correct[i] != got["z" + code]) {
            cout << 'z' << code << " -> " << correct[i];
            cout << " | " << got["z" + code] << '\n';
        }
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}
