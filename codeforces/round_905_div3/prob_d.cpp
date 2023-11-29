#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    int l, r;
    char sign;
    vector<pair<int,int>> vec;

    bool before;
    int max_l, min_r; // to intersect all
    while (t--) {
        cin >> sign >> l >> r;

        // building vector
        if (sign == '+') {
            vec.push_back({l, r});
            std::sort(vec.begin(), vec.end());

        } else {
            for (auto it = vec.begin(); it != vec.end();) {
                if (it->first == l && it->second == r) {
                    vec.erase(it);
                    break;
                } else it++;
            }
        }

        if (vec.size() <= 1) {
            cout << "No" << '\n';
            before = false;
            if (vec.size() >0) {
                max_l = vec[0].second;
                min_r = vec[0].first;
            }
        } else {
            if (sign == '+') {
                if (before) cout << "Yes" << '\n';
                else {
                    if (l <= max_l && r >= min_r) {
                        cout << "No" << '\n';
                        before = false;
                    } else {
                        cout << "Yes" << '\n';
                        if (l > min_r) min_r = l;
                        if (r < max_l) max_l = r;
                        before = true;
                    }
                }
            } else {
                if (before) {
                    cout << "Yes" << '\n';
                    before = true;
                } else {

                    max_l = vec[0].second;
                    min_r = vec[0].first;
                    for (int i = 1; i< vec.size(); i++) {
                        if (vec[i].first > min_r) min_r = l;
                        if (vec[i].second < max_l) max_l = r;
                    }

                    bool yes = true;
                    for (int i = 0; i < vec.size(); i++) {
                        if (! (l <= max_l && r >= min_r) ) {
                            cout << "Yes" << '\n';
                            yes = false;
                            break;
                        }
                    }
                    if (yes) cout << "No" << '\n';

                }


            }



        }





        /*
        if (sign == '-') {
            // to print
            if (vec.size() <= 1) cout << "No" << '\n';
            else {
                bool no = true;

                for (int i = 0; i < vec.size(); i++) {
                    int my_l = vec[i].first, my_r = vec[i].second;
                    bool flag = false;
                    for (int j = vec.size() - 1; j > i; j--) {
                        if (vec[j].first > my_r) {
                            cout << "Yes" << '\n';
                            flag = true;
                            no = false;
                            break;
                        }
                    }
                    if (flag) break;
                }

                if (no) cout << "No" << '\n';

            }
        } else {

        }
         */
    }


}
