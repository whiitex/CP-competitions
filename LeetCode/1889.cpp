class Solution {
public:
	int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
		int n = packages.size(), m = boxes.size();
		sort(packages.begin(), packages.end());

		vector<pair<long long, long long>> pref(n);  // (sum, max)
		long long sum = 0, mx = 0;
		for (int i=0; i<n; ++i) {
			sum += packages[i];
			mx = max(mx, (long long)packages[i]);
			pref[i] = {sum, mx};
		}

		long long ans = 1e18;
		for (auto sup: boxes) {
			sort(sup.begin(), sup.end());
			if (sup[sup.size() - 1] < packages[n-1]) continue;

			long long tot = n, t = 0, s = 0, waste = 0;
			while (t < tot) {

				long long box = sup[s++];
				long long l = t, r = tot-1;
				while (l < r) {

					int mid = (l + r + 1ll) >> 1;
					if (pref[mid].second > box) r = mid - 1;
					else l = mid;
				}

				if (l == t and pref[l].second > box) continue;

				waste += box * (l + 1 - t);
				waste -= pref[l].first;
				if (t > 0) waste += pref[t-1].first;
				t = l + 1;
			}
			ans = min(ans, waste);
		}

		if (ans == (long long)1e18) return -1;
		return ans % (long long)(1e9+7);
	}
};