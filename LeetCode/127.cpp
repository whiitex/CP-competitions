class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = (int)wordList.size();
        auto diff = [] (string& s, string& t) -> int {
            assert(s.size() == t.size());
            int res = 0;
            for (int i=0; i<s.size(); ++i) res += s[i] != t[i];
            return res;
        };

        vector<int> dp(n), vis(n);
        queue<int> q; q.push(-1);
        set<int> rem; for (int i=0; i<n; ++i) rem.insert(i);
        while (!q.empty()) {
            int i = q.front(); q.pop();
            if (i != -1 and vis[i]) continue;
            if (i != -1) vis[i] = 1;

            string s = i == -1 ? beginWord : wordList[i];

            vector<int> to_erase;
            for (int j: rem) {
                if (diff(wordList[j], s) == 1) {
                    dp[j] = i == -1 ? 2 : dp[i] + 1;
                    cout << wordList[j] << ' ' << dp[j] << '\n';
                    if (wordList[j] == endWord) return dp[j]; 
                    to_erase.push_back(j);
                    q.push(j);
                }
            }
            for (int p: to_erase) rem.erase(p);
        }

        return 0;
    }
};