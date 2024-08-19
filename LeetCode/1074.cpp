class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = (int) matrix.size(), col = (int) matrix[0].size();
        vector<vector<int>> pref(row, vector<int>(col)); pref[0][0] = matrix[0][0];
        
        for (int i=0; i<row; ++i) {
            for (int j=(i==0?1:0); j<col; ++j) {
                if (i == 0) pref[i][j] = pref[i][j-1] + matrix[i][j];
                else if (j == 0) pref[i][j] = pref[i-1][j] + matrix[i][j];
                else pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + matrix[i][j];
            }
        }

        int ans = 0;
        for (int i=0; i<row; ++i) {
            for (int j=0; j<col; ++j) {

                // end corner
                for (int ei=i; ei<row; ++ei) {
                    for (int ej=j; ej<col; ++ej) {
                        
                        int tot = 0;
                        if (i == 0 and j == 0) tot = pref[ei][ej];
                        else if (i == 0) tot = pref[ei][ej] - pref[ei][j-1];
                        else if (j == 0) tot = pref[ei][ej] - pref[i-1][ej];
                        else tot = pref[ei][ej] - pref[ei][j-1] - pref[i-1][ej] + pref[i-1][j-1];
                        if (tot == target) ++ans;
                    }
                }

            }
        }

        return ans;
    }
};