class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;

        for (int i = 0; i < n; ++i) {
            int tot = words[i].size(), spaces = 0;
            int j = i;
            while (j < n - 1 and words[j + 1].size() + 1 + tot <= maxWidth) {
                tot += words[j + 1].size() + 1;
                ++spaces;
                ++j;
            }

            string s;
            if (j == n - 1) {
                for (int k = i; k <= j; ++k) {
                    for (char c : words[k])
                        s.push_back(c);
                    s.push_back(' ');
                }
                s.pop_back();
            } else {
                int div = j - i;
                spaces = maxWidth - tot + spaces;
                for (int k = i; k <= j; ++k) {
                    for (char c : words[k])
                        s.push_back(c);
                    if (div) {
                        int sp = (spaces + div - 1) / div;
                        --div;
                        for (int o = 0; o < sp; ++o)
                            s.push_back(' ');
                        spaces -= sp;
                    }
                }
            }

            while (s.size() < maxWidth) s.push_back(' ');
            ans.push_back(s);
            i = j;
        }
        return ans;
    }
};