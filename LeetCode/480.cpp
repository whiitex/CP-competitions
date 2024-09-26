class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& vec, int k) {
        multiset<double> big, low;
        vector<double> ans;

        for (int i=0; i<k; ++i) big.insert(vec[i]);
        for (int i=0; i<k - (k/2+1); ++i) {
            low.insert(*big.begin());
            big.erase(big.begin());
        }

        ans.push_back(k % 2 ? *big.begin() : (*big.begin() + *(++big.begin())) / 2);
        for (int i=k; i<vec.size(); ++i) {
            if (low.contains(vec[i-k])) low.erase(low.find(vec[i-k]));
            else big.erase(big.find(vec[i-k]));

            low.insert(vec[i]);
            
            while (big.size() < k/2 + 1) {
                big.insert(*low.rbegin());
                low.erase(low.find(*low.rbegin()));
            }

            if (!low.empty()) while (*low.rbegin() > *big.begin()) {
                int mnbig = *big.begin();
                big.erase(big.begin());
                big.insert(*low.rbegin());
                low.erase(low.find(*low.rbegin()));
                low.insert(mnbig);
            }

            ans.push_back(k % 2 ? *big.begin() : (*big.begin() + *(++big.begin())) / 2);
        }

        return ans;
    }
};