class Solution {
public:
	int maxDistance(int side, vector<vector<int>>& p, int k) {
        long long s = side;
		long long n = p.size(), m = s * 4;
		vector<long long> a(n); for (int i=0; i<n; ++i) {
			if (p[i][1] == 0) a[i] = p[i][0];
			else if (p[i][0] == s) a[i] = p[i][1] + s;
			else if (p[i][1] == s) a[i] = 3*s - p[i][0];
			else a[i] = 4*s - p[i][1];
		}
		sort(a.begin(), a.end());

		auto check = [&] (long long x) -> bool {
			for (long long i=0; i<n; ++i) {
				long long now = a[i], ok = 1, span = 0;
				for (long long cnt=0; cnt<k and ok; ++cnt) {
					auto it = lower_bound(a.begin(), a.end(), now + x);
					if (it == a.end()) {
						long long find = now + x < m ? 0 : (now + x) % m;
						it = lower_bound(a.begin(), a.end(), find);
					}

					if (*it > now) span += *it - now;
					else span += (m - now + *it);
					now = *it;
					if (span > m) ok = 0;
				}
				if (ok) return true;
			}
			return false;
		};

		long long l = 1, r = s * 4 / k;
		while (l < r) {
			long long mid = l + r + 1 >> 1;
			if (check(mid)) l = mid;
			else r = mid - 1;
		}

		return l;
	}
};