class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<bool> mp(n, 0);
        stack<pair<int,int>> q;
        for (int i=0; i<n; ++i) {
            bool popped = false;
            if (!q.empty() and s[i] == ')' and  q.top().first == 0) {
                mp[i] = 1;
                mp[q.top().second] = 1;
                q.pop();
                popped = true;
            }
            if (!popped) {
                q.push({s[i] == '(' ? 0 : 1, i});
            }

        }

        int ans = 0;
        for (int i=0; i<n; ++i) {
            int j = i;
            while (j < n and mp[j] == 1) ++j;
            ans = max(ans, j-i);
            i = j;
        }

        return ans;
    }
};