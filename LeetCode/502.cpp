class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = (int)profits.size();

        vector<int> o(n);
        iota(o.begin(), o.end(), 0);
        sort(o.begin(), o.end(), [&](int x, int y) -> bool {
            return capital[x] < capital[y];
        });

        priority_queue<int> pq;
        int i = 0;

        while (k--) {
            while (i < n and capital[o[i]] <= w) {
                pq.push(profits[o[i]]);
                ++i;
            }

            if (pq.empty()) break;
            int add = pq.top(); pq.pop();
            w += add;
        }

        return w;
    }
};