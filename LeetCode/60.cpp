class Solution {
public:
    string getPermutation(int n, int k) {
        return getP(n, k, "");
    }

private:
    string getP(int n, int rem, string s) {
        if (s.size() == n) return s;
        vector<int> vec;
        set<int> no;
        if (!s.empty()) for (char c: s) no.insert(c-'0');
        for (int i=1; i<=n; ++i) if (!no.contains(i)) vec.push_back(i);
        
        int i=0, count = fact(n-s.size()-1);
        while (i < vec.size()-1 and count < rem) {
            ++i;
            count += fact(n-s.size()-1);
        } 
        
        count -= fact(n-s.size()-1);
        s.push_back(vec[i] + '0');
        return getP(n, rem - count, s);
    }

    int fact(int n) {
        if (n <= 1) return 1;
        else return n * fact(n-1);
    }
};