class Solution {
struct DSU {
    vector<int> odd; // odd cnt
	explicit DSU(int n): Par(n), Sz(n, 1), odd(n) {
		iota(Par.begin(), Par.end(), 0);
        for (int i=0; i<n; ++i) odd[i] += i & 1;
	}

	int find(int node) {
		if (Par[node] == node) return node;
		return Par[node] = find(Par[node]);
	}

	void merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (Sz[a] < Sz[b]) swap(a, b);
		Par[b] = a; Sz[a] += Sz[b];
        odd[a] += odd[b]; // update cnt odd
	}
    private: vector<int> Par, Sz;
};

public:
    long long maxAlternatingSum(vector<int>& a, vector<vector<int>>& swaps) {
        int n = a.size();
        
        DSU dsu(n);
        for (auto &v: swaps) dsu.merge(v[0], v[1]);

        vector l(n, vector<long long>());
        for (int i=0; i<n; ++i) {
            l[dsu.find(i)].push_back((long long)a[i]);
        }

        long long ans = 0;
        for (int i=0; i<n; ++i) if (!l[i].empty()) {
            sort(l[i].begin(), l[i].end());
            int rem = dsu.odd[i];

            for (int j=0; j<rem; ++j) ans -= l[i][j];
            for (int j=rem; j<l[i].size(); ++j) ans += l[i][j];
        }

        return ans;
    }
};