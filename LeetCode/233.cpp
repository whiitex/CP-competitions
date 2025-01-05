class Solution {
public:
    int countDigitOne(int n) {
        string sn = to_string(n);
        vector<long long> ten(10, 1); sn = '0' + sn + '0';
        for (int i=1; i<10; ++i) ten[i] = ten[i-1] * 10;
    
        long long ans = 0;
        for (int i=1; i<sn.size()-1; ++i) {
            int pw = sn.size() - i - 2;

            if (sn[i] - '0' > 1) ans += ten[pw];
            else if (sn[i] - '0' == 1) ans += stoi(sn.substr(i+1, max(1,pw))) +1;
            ans += (pw+1ll) * ten[pw] * int(sn[i-1] - '0');
        }

        return ans;        
    }
};