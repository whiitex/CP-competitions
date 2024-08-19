class Solution {
    bool can(vector<int>& poss, vector<int>& need) {
        for (int i=0; i<poss.size(); ++i) if (poss[i] < need[i]) return false;
        return true;
    }

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int MAXN = 300, ans = 0;
        vector<vector<vector<int>>> dp(MAXN);
        vector<int> init(30);
        for (char c: letters) ++init[c - 'a'];
        dp[0].push_back(init);

        for (string w: words) {
            int wscore = 0;
            vector<int> need(30);
            for (char c: w) { ++need[c - 'a']; wscore += score[c - 'a']; }

            for (int i=MAXN-1; i>=0; --i) {
                for (auto poss: dp[i]) {
                    if (can(poss, need)) {
                        ans = max(ans, i + wscore);
                        vector<int> left(30);
                        for (int i=0; i<30; ++i) left[i] = poss[i] - need[i];
                        dp[i + wscore].push_back(left);
                    }
                }
            }
        }

        return ans;
    }
};