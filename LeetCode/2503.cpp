class Solution {
    typedef array<int,3> a3;

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& quer) {
        int k = quer.size(), m = grid.size(), n = grid[0].size();
        vector<int> ans(k);
        vector<pair<int,int>> queries(k);
        for (int i=0; i<k; ++i) queries[i] = {quer[i], i};
        sort(queries.begin(), queries.end());

        priority_queue<a3, vector<a3>, greater<a3>> pq;
        pq.push({grid[0][0], 0, 0});

        bool visited[m][n]; memset(visited, 0, sizeof(visited));

        int prev = 0;
        for (auto Query: queries) {
            int query = Query.first;

            while (!pq.empty() and pq.top()[0] < query) {
                auto t = pq.top(); pq.pop();
                int x = t[1], y = t[2];

                if (visited[x][y]) continue;                
                visited[x][y] = true;
                
                if (x+1 < m && !visited[x+1][y]) pq.push({grid[x+1][y], x+1, y});
                if (x-1 >=0 && !visited[x-1][y]) pq.push({grid[x-1][y], x-1, y});
                if (y+1 < n && !visited[x][y+1]) pq.push({grid[x][y+1], x, y+1});
                if (y-1 >=0 && !visited[x][y-1]) pq.push({grid[x][y-1], x, y-1});

                ++prev;
            }

            ans[Query.second] = prev;
        }

        return ans;
    }
};