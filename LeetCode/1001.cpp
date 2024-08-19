class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps,vector<vector<int>>& queries) {
        unordered_map<int,int> row, col, diagu, diagd;
        set<pair<int, int>> lampset;
        for (auto pos : lamps) {
            if (lampset.find({pos[0], pos[1]}) != lampset.end())
                continue;
            lampset.insert({pos[0], pos[1]});
            ++row[pos[0]];
            ++col[pos[1]];
            ++diagu[n - 1 - pos[1] + pos[0]];
            ++diagd[pos[0] + pos[1]];
        }

        vector<int> ans(queries.size());
        for (int j = 0; j < queries.size(); ++j) {
            auto pos = queries[j];
            bool flag = false;
            flag |= row[pos[0]];
            flag |= col[pos[1]];
            flag |= diagu[n - 1 - pos[1] + pos[0]];
            flag |= diagd[pos[0] + pos[1]];
            ans[j] = int(flag);

            for (int xx : {-1,0,1}) for (int yy : {-1,0,1}) {
                int x = pos[0] + xx, y = pos[1] + yy;
                if (lampset.find({x, y}) != lampset.end()) {
                    lampset.erase({x, y});
                    --row[x];
                    --col[y];
                    --diagu[n - 1 - y + x];
                    --diagd[x + y];
                }
            }
        }

        return ans;
    }
};