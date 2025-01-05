class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = (int)s1.size();
        int dp[31][31][31][31]; 
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
            for (int k=0; k<n; ++k) for (int q=0; q<n; ++q)
                dp[i][j][k][q] = -1;
        }

        auto solve = [&] (auto f, int s, int e, int ss, int ee) -> bool {
            // cout << s << ' ' << e << ' ' << ss << ' ' << ee << '\n';
            if (dp[s][e][ss][ee] != -1) return dp[s][e][ss][ee];
            if (e == s) return dp[s][e][ss][ee] = s1[s] == s2[ss];

            int ok = 0, span = e-s+1;
            for (int i=0; i<=span-2; ++i) {
                ok |= f(f, s, s+i, ss, ss+i) and f(f, s+i+1, e, ss+i+1, ee);
                ok |= f(f, s, s+i, ee-i, ee) and f(f, s+i+1, e, ss, ee-i-1);
            }
            return dp[s][e][ss][ee] = ok;
        };

        return solve(solve, 0, n-1, 0, n-1);
    }
};