#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back
const int MXN = 5e5 + 5;


vi sieve(MXN), primes;

void solve() {
	int n; cin >> n;

	vi a(n+1); iota(a.begin(), a.end(), 0);
	int pi = 0; while (primes[pi + 1] * 2 <= n) ++pi;

	vi done(n+1);
	for (; pi >= 0; --pi) {
		int p = primes[pi];

		vi sw;
		for (int i=1; p * i <= n; ++i) {
			if (!done[i * p]) {
				sw.pb(i * p);
				done[i * p] = 1;
			}
		}

		for (int i=1; i<(int)sw.size(); ++i) swap(a[sw[i]], a[sw[i-1]]);
	}

	for (int i=1; i<=n; ++i) cout << a[i] << ' '; cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int p=2; p<MXN; ++p) if (!sieve[p]) {
		primes.pb(p);
		for (int i=p; i<MXN; i+=p) sieve[i] = p;
	}

	int t = 1; cin >> t;
	while (t--) solve();
}
