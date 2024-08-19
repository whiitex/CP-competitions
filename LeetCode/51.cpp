class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        auto solve = [&] (auto self, vector<vector<int>>& free, int r, int k) {
            if (k == n) {
                vector<string> toadd;
                for (int i=0; i<n; ++i) {
                    string s;
                    for (int j=0; j<n; ++j)
                        s.push_back(free[i][j] == 2 ? 'Q' : '.');
                    toadd.push_back(s);
                }
                ans.push_back(toadd);
                return;
            }
            for (int i=r+1; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    if (free[i][j]) {
                        vector<vector<int>> free2(free);
                        for (int o=0; o<n; ++o) {
                            free2[o][j] = 0;
                            free2[i][o] = 0;
                            if (i+o < n and j+o < n) free2[i+o][j+o] = 0;
                            if (i+o < n and j-o >=0) free2[i+o][j-o] = 0;
                            if (i-o >=0 and j+o < n) free2[i-o][j+o] = 0;
                            if (i-o >=0 and j-o >=0) free2[i-o][j-o] = 0;
                        }
                        free2[i][j] = 2;
                        self(self, free2, i, k+1);
                    }
                }
            }
            return;
        };

        vector<vector<int>> free(n, vector<int>(n, 1));
        solve(solve, free, -1, 0);
        return ans;
    }
};