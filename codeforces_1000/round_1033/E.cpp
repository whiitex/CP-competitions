#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

const int INF = 8e18;

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); for (int &i: a) cin >> i;

	if (n == 1) { cout << a[0] * (a[0]+1) / 2 << '\n'; return; }

    sort(a.begin(), a.end(), greater<>());

	int tot = accumulate(a.begin(), a.end(), 0ll);
	vi obj(n);
	for (int i=0, t=tot; i<n; ++i) {
		int m = n - i;
		obj[i] = (t + m - 1) / m;
		t -= obj[i];
	}

	int R = 0;
	for (int i=0; i<n; ++i) {
		R += max(0ll, a[i] - obj[i]);
	}

	auto check = [&] (int x) -> int {
		if (x < 0 or x > R) return INF;
		vi b(a);

		if (x) {
			int rem = x, i = 1;
			for (; i<n; ++i) {
				int add = (a[i-1] - a[i]) * i;
				if (rem - add < 0) break;
				rem -= add;
			} --i;

			for (int j=0; j<=i; ++j) {
				int m = i + 1 - j;
				int bonus = (rem + m - 1) / m;
				b[j] = a[i] - bonus;
				rem -= bonus;
			}

			rem = x, i = n-2;
			for (; i>=0; --i) {
				int add = (a[i] - a[i+1]) * (n-i-1);
				if (rem - add < 0) break;
				rem -= add;
			} ++i;

			for (int j=i; j<n; ++j) {
				int m = n - j;
				int bonus = (rem + m - 1) / m;
				b[j] = a[i] + bonus;
				rem -= bonus;
			}

		}

		int ans = k * x;
		for (int y: b) ans += y * (y + 1) / 2;
		return ans;
	};

	int l=0, r=R;
	while (l + 1 < r) {
		int x1 = (2 * l + r) / 3;
		int x2 = (l + 2 * r) / 3;

		int c1 = check(x1);
		int c2 = check(x2);

		if (c1 == c2) l = x1, r = x2;
		if (c1 < c2) r = x2 - 1;
		else l = x1 + 1;
	}

	int ans = min({check(l), check(l+1), check(l-1)});

	cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}