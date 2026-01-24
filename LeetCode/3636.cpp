class Solution {
public:
	vector<int> subarrayMajority(vector<int>& a, vector<vector<int>>& queries) {

		int n = (int)a.size();

		vector<array<int, 4>> q;
		for (int i=0; i<(int)queries.size(); i++) {
			int l = queries[i][0], r = queries[i][1], t = queries[i][2];
			q.push_back({l, r, t, i});
		}

		sort(q.begin(), q.end(), [] (const array<int, 4>& x, const array<int, 4>& y) -> bool {
			if (x[0] == y[0]) return x[1] < y[1];
			return x[0] > y[0];
		});

		int L = n, R = n; a.push_back(-1);
		unordered_map<int,int> mp;

		map<array<int,3>, int> save;

		vector<int> ANS(queries.size());
		for (auto v: q) {
			int l = v[0], r = v[1], t = v[2], idx = v[3];

			++r;

			if (!save.contains({l, r, t})) {
				while (L > l) { --L; ++mp[a[L]]; }
				while (R > r) { --R; --mp[a[R]]; }
				while (R < r) { ++mp[a[R]]; ++R; }

				int ans = -1, high = t;
				for (auto& [k, v]: mp) {
					if (v > high) ans = k, high = v;
					if (v == high) ans = ans == -1 ? k : min(ans, k);
				}
				save[{l, r, t}] = ans;
			}
			ANS[idx] = save[{l, r, t}];
		}

		return ANS;
	}
};