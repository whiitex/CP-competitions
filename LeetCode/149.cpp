class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        int ans = 1;
        for (int i=0; i<n-1; ++i) for (int j=i+1; j<n; ++j) {
            int px = points[i][0], py = points[i][1];
            int qx = points[j][0], qy = points[j][1];
            
            int dx = px - qx;
            int dy = py - qy;
            int gcd = __gcd(abs(dx), abs(dy));
            dx /= gcd; dy /= gcd;

            int cnt = 1;
            for (int k=0; k<n; ++k) if (k != i) {
                int DX = px - points[k][0];
                int DY = py - points[k][1];
                if (dx != 0 and dy != 0 and DX % dx == 0 and DY % dy == 0 and DX / dx == DY / dy) ++cnt;
                if (dx == 0 and px == points[k][0]) ++cnt;
                if (dy == 0 and py == points[k][1]) ++cnt;
            }
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};