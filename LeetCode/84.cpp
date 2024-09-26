class Solution {
public:
    int largestRectangleArea(vector<int>& vec) {
        int n = vec.size();
        priority_queue<pair<int,int>> pq;
        vector<array<int,3>> pos(n+2);
        for (int i=0; i<n+2; ++i) pos[i] = {0, i, i};
        for (int i=0; i<n; ++i) pq.push({vec[i], i+1});

        int ans = 0;
        while (!pq.empty()) {
            int h = pq.top().first;
            if (h == 0) break;
            int mx = 1;
            while (!pq.empty() and pq.top().first == h) {
                int p = pq.top().second; pq.pop();
                pos[p][0] = 1;
                if (pos[p-1][0] and pos[p+1][0]) {
                    pos[pos[p-1][1]][0] += pos[p][0] + pos[p+1][0];
                    pos[pos[p+1][2]][0] = pos[pos[p-1][1]][0];
                    mx = max(mx, pos[pos[p+1][2]][0]);

                    pos[pos[p-1][1]][2] = pos[p+1][2];
                    pos[pos[p+1][2]][1] = pos[p-1][1];
                } else if (pos[p-1][0]) {
                    pos[p][0] += pos[p-1][0];
                    pos[pos[p-1][1]][0] = pos[p][0];
                    mx = max(mx, pos[p][0]);

                    pos[pos[p-1][1]][2] = p;
                    pos[p][1] = pos[p-1][1];
                } else if (pos[p+1][0]) {
                    pos[p][0] += pos[p+1][0];
                    pos[pos[p+1][2]][0] = pos[p][0];
                    mx = max(mx, pos[p][0]);

                    pos[pos[p+1][2]][1] = p;
                    pos[p][2] = pos[p+1][2];
                }
            }

            ans = max(ans, h * mx);
        }

        return ans;
    }
};