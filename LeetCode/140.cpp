class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector dict(11, vector<string>());
        for (string t: wordDict) dict[t.size()].push_back(t);

        vector<string> ans; vector<int> v;
        auto rec = [&] (auto f, int x) -> void {
            if (x == s.size()) {
                string t;
                for (int i=0, j=1; i<s.size(); ++i) {
                    if (j<v.size() and i == v[j]) t.push_back(' '), ++j;
                    t.push_back(s[i]);
                }
                ans.push_back(t);
                return;
            }

            for (int span=1; span <= min(10, (int)s.size()-x); ++span) {
                string match = s.substr(x, span);
                for (string t: dict[span]) if (t == match) {
                    v.push_back(x);
                    f(f, x+span);
                    v.pop_back();
                }
            }

        }; rec(rec, 0);
        
        return ans;
    }
};