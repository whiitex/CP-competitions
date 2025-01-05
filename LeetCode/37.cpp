class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = 9;
        
        auto possible = [&] (int i, int j, char c) -> bool {
            for (int k=0; k<n; ++k) if (board[i][k] == c) return false;
            for (int k=0; k<n; ++k) if (board[k][j] == c) return false;
            int row = i/3, col = j/3;
            for (int a=row*3; a<row*3+3; ++a) for (int b=col*3; b<col*3+3; ++b) {
                if (board[a][b] == c) return false;
            }
            return true;
        };

        auto solve = [&] (auto f, int I, int J) -> bool {
            for (int i=I; i<n; ++i) for (int j= (i==I ? J : 0); j<n; ++j) {
                if (board[i][j] != '.') continue;
                for (char c='1'; c<='9'; ++c) if (possible(i, j, c)) {
                    board[i][j] = c;
                    if (f(f, i, j)) return true;
                    board[i][j] = '.';
                }
                return false;
            }
            
            return true;
        };

        solve(solve, 0, 0);
    }
};