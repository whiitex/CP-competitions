#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d, n_sets=0, x, y;
    cin >> n >> d;

    set<int> sets[2*n];

    for (int i=1; i<=d; i++) {
        cin >> x >> y;

        // initialization
        if (i==0) {
            sets[0].insert(x);
            sets[0].insert(y);
            n_sets++;
            cout << 1 << '\n';

        // general case
        } else {
            bool add_set = true;
            for (int j=0; j<n_sets; j++) {
                if (sets[j].find(x) != sets[j].end() || sets[j].find(y) != sets[j].end()) {
                    sets[j].insert(x);
                    sets[j].insert(y);
                    add_set = false;
                    break;
                }
            }
            if (add_set) {
                sets[n_sets].insert(x);
                sets[n_sets].insert(y);
                n_sets++;
            }

            // check merging sets
            for(int j: {x, y}) {
                vector<int> to_merge;
                for (int s = 0; s < n_sets; s++) {
                    if (sets[s].find(j) != sets[s].end())
                        to_merge.push_back(s);
                }
                if (to_merge.size() > 1) {
                    int first = to_merge.front();
                    for (int set : to_merge)
                        if (set != first) {
                            for (int numb:sets[set])
                                sets[first].insert(numb);
                            sets[set].clear();
                        }
                }
            }

            // compute solution
            set<int> valid_sets;
            int total_cont=0, ans=0;
            for (int j=0; j<n_sets; j++)
                if (!sets[j].empty()) {
                    valid_sets.insert(j);
                    total_cont += sets[j].size();
                    if (sets[j].size() - 1 > ans)
                        ans = sets[j].size() - 1;
                }

            int rem = i - total_cont + valid_sets.size();

            for (int set : valid_sets)
                if (sets[set].size() - 1 == ans) {
                    valid_sets.erase(set);
                    break;
                }

            // add bonus lines
            while(rem--) {
                if (valid_sets.size() > 0) {
                    int max = 0, index;
                    for (int set: valid_sets)
                        if (sets[set].size() > max) {
                            index = set;
                            max = sets[set].size();
                        }
                    ans += max;
                    valid_sets.erase(index);
                } else ans++;
            }

            cout << ans << '\n';
        }


    }

}
