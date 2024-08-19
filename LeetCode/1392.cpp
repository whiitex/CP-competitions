class Solution {
    string KMP(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; ++i) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return s.substr(0, pi[n-1]);
    }
public:
    string longestPrefix(string s) {
        return KMP(s);
    }
};