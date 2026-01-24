class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = (int)s.size();

        int par = 0;
        vector<string> ck(n+10), cs(n+10);
        for (int i=0; i<n; ++i) {
            if (s[i] == '(' or s[i] == ')') {
                ++par;
                cs[par] = s[i];
            } else {
                int j = i; string g;
                while (j < n and s[j] != '(' and s[j] != ')') {
                    g.push_back(s[j]);
                    ++j;
                }
                ck[par] = g;
                i = j - 1;
            }
        }
        
        int mn = 234;
        set<string> ans;
        for (int mask=0; mask<1<<(par+1); mask+=2) {
            string g;
            int rem = 0;
            for (int bit=0; bit<par+1; ++bit) {
                if ((mask >> bit) & 1) g.append(cs[bit]);
                else ++rem;
                g.append(ck[bit]);
            }

            if (rem > mn) continue;

            bool ok = 1;
            for (int i=0, c=0; i<(int)g.size(); ++i) {
                c += g[i] == '(' ? 1 : g[i] == ')' ? -1 : 0;
                if (c < 0) ok = 0;
                if (i == (int)g.size() - 1 and c != 0) ok = 0;
            }

            if (!ok) continue;

            if (rem < mn) {
                ans.clear();
                mn = rem;
            }
            ans.insert(g);
        }

        vector<string> vs;
        for (string g: ans) vs.push_back(g);
        return vs;
    }
};