class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = (int)wordList.size();
        set<string> st; for (string s: wordList) st.insert(s);
        map<string, int> mp; for (int i=0; i<n; ++i) mp[wordList[i]] = i;
        vector<int> dp(n), vis(n);
        queue<int> que; que.push(-1);
        int len = -1;
        while (!que.empty()) {
            int i = que.front(); que.pop();
            if (i != -1 and vis[i]) continue;
            if (i != -1) vis[i] = 1;

            string s = i == -1 ? beginWord : wordList[i];
            if (s == endWord) { len = dp[i]; break; }
            for (int pos=0; pos<s.size(); ++pos) for (char c='a'; c<='z'; ++c) {
                string t = s; t[pos] = c; 
                if (s != t and st.contains(t) and !dp[mp[t]]) {
                    int j = mp[t];
                    dp[j] = i == -1 ? 2 : dp[i] + 1;
                    que.push(j);
                }
            }
        }

        vector<vector<string>> ans;
        if (len == -1) return ans;
        
        cout << len << '\n';
        auto dfs = [&] (auto f, vector<int>& v) -> void {
            int i = v.back(); string s = wordList[i];
            if (dp[i] == 2) {
                vector<string> to_push = {beginWord};
                for (int p=v.size()-1; p>=0; --p) to_push.push_back(wordList[v[p]]);
                ans.push_back(to_push);
            } 
            
            else for (int pos=0; pos<s.size(); ++pos) for (char c='a'; c<='z'; ++c) {
                string t = s; t[pos] = c; 
                if (s != t and st.contains(t)) {
                    int j = mp[t];

                    if (dp[j] == dp[i] - 1) {
                        v.push_back(j);
                        f(f, v);
                        v.pop_back();
                    }
                    
                }
            }

        };

        vector<int> v = {mp[endWord]};
        dfs(dfs, v);
        return ans;
    }
};