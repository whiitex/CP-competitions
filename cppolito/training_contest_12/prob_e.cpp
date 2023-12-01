#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    int temp;
    for (int i=0; i<n; ++i)
        cin >> vec[i];

    unordered_map<int, pair<int,int>> m;
    m.insert({0, {0,0}});
    for (int i=n-1; i>=0; --i) {
        if (m.find(vec[i]) == m.end()) {
            if (m.find(vec[i] + 1) != m.end())
                m.insert({vec[i], {m[vec[i] + 1].first + 1, vec[i] + 1}});
            else m.insert({vec[i], {1, 0}});
        } else if (m.find(vec[i] + 1) != m.end())
            m[vec[i]] = {m[vec[i] + 1].first + 1, vec[i] + 1};
    }

    int h = 0, value;
    for (auto p: m) {
        if (h < p.second.first) {
            h = p.second.first;
            value = p.first;
        }
    }

    if (h == 1)
        cout << 1 << '\n' << 1 << '\n';
    else {
        cout << h << '\n';
        vector<int> pos;

        int i=0;
        int next = value;
        while (next != 0 and i<n) {
            if (vec[i] == next) {
                pos.push_back(i);
                next = m[next].second;
            }
            ++i;
        }

        for (int k: pos)
            cout << k+1 << ' ';
        cout << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}


/*  TIME LIMIT EXCEEDED
    int n;
    cin >> n;
    vector<pair<int,int>> vec(n);
    int temp;
    for (int i=0; i<n; ++i) {
        cin >> temp;
        vec[i] = {temp, i+1};
    }

    sort(vec.begin(), vec.end());

    vector<int> solution;
    solution.push_back(1);
    vector<int> possible;

    for (int i=0; i<n-1; ++i) {
        int j = i;

        vector<queue<int>> position;
        queue<int> v; v.push(vec[j].second);
        position.push_back(v);
        int current = vec[j].first;
        while (current == vec[j+1].first or current + 1 == vec[j+1].first) {
            if (current == vec[j+1].first) {
                position[position.size() - 1].push(vec[j+1].second);
            } else {
                queue<int> a;
                a.push(vec[j+1].second);
                position.push_back(a);
            }
            current = vec[j+1].first;
            ++j;
        }

        int least = position[0].front();
        possible.push_back(least);
        for (int k=1; k<position.size(); ++k) {
            while(position[k].front() < least and !position[k].empty())
                position[k].pop();

            if (position[k].empty())
                break;
            else {
                possible.push_back(position[k].front());
                least = position[k].front();
            }
        }

        if (possible.size() > solution.size()) {
            solution.clear();
            for (int q : possible)
                solution.push_back(q);
        }
        // i += possible.size() - 1;
        possible.clear();

    }


    // print solution
    cout << solution.size() << '\n';
    for(int p: solution)
        cout << p << ' ';
    cout << '\n';
 */


 /* SAME PROBLEM WITH TIME LIMIT
    // vector of possible consecutive numbers
    vector<vector<int>> vec;
    for (int i=0; i<n; ++i) {
    // remove all first equale points
    while (array[i].first == array[i+1].first)
    ++i;

    // build vector of consequences
    int j=i;
    while (array[j].first == array[j+1].first or array[j].first + 1 == array[j+1].first) {
    if (array[j].first + 1 == array[j+1].first) {
    if (i==j) {
    vector<int> v = {array[j].first, array[j+1].first};
    vec.push_back(v);
    } else
    vec.back().push_back(array[j+1].first);
    }
    ++j;
    }
    }

    // sort by decreasing order of vector size
    sort(vec.begin(), vec.end(), [] (const vector<int>& x, const vector<int>& y) -> bool { return x.size() > y.size(); });

    // scan all original array looking for cons
    int maxcons = 0, maxindex;
    int index = 0;
    while (maxcons < vec[index].size()) {

    vector<int> current = vec[index];
    int taker[current.size()];
    memset(taker, 0, sizeof(taker));
    for (int i=0; i<n; ++i) {
    for (int j=0; j<current.size(); ++j)
    if (array[i].first == current[j]) {
    if (j>0) taker[j] = taker[j-1] + 1;
    else taker[0] = 1;
    }
    }

    int m = 0, ind;
    for(int i=0; i<current.size();++i)
    if (m < taker[i]) {
    m = taker[i];
    ind = 1;
    }

    if (m > maxcons) maxcons = m;
    ++index;
    }
*/