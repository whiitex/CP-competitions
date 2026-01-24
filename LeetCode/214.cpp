class Solution {
    int KMP(string& s) {
        vector<int> pref;
        int n = (int) s.length();
        pref.resize(n);
        
        int mlen = 0;
        for (int i = 1; i < n; ++i) {
            while (mlen > 0 and s[mlen] != s[i])
                mlen = pref[mlen - 1];
        
            if (s[mlen] == s[i]) ++mlen;
            pref[i] = mlen;
        }
        return pref.back();
    }
public:
    string shortestPalindrome(string s) {
        int n = (int)s.size();

        string g = s + '$';
        string rs = s; reverse(rs.begin(), rs.end());
        g += rs;

        int mxlen = KMP(g);
        int toadd = n - mxlen;

        for (int i=n-toadd; i<n; ++i) rs.push_back(s[i]);
        reverse(rs.begin(), rs.end());
        return rs;
    }
};