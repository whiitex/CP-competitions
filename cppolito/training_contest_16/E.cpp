#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;

#define pb push_back
#define f first
#define s second

const int MAXP = 1e6+6;
int primes[MAXP];
map<int,int> nmap, original;

void solve() {
    int n, q; cin >> n >> q;

    auto factorize = [&] (int num, map<int,int>& mp) -> void {
        while (num > 1) {
            ++mp[primes[num]];
            num /= primes[num];
        }
    };

    factorize(n, original);
    nmap = original;

    while (q--) {
        int k; cin >> k;

        if (k == 2) {
            nmap.clear();
            nmap = original;
        }

        else {

            int x; cin >> x;
            factorize(x, nmap);

            map<int,int> dmap;
            for (pii p: nmap)
                factorize(p.s+1, dmap);

            bool ok = true;
            for (pii p: dmap)
                if (p.s > nmap[p.f]) ok = false;

            if (ok) cout << "Yes\n";
            else cout << "No\n";

            dmap.clear();
        }

    }

    nmap.clear();
    original.clear();
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // complexity O(1e7)
    memset(primes, 0, sizeof(primes));

    for (int i=2; i<MAXP; i+=2) primes[i] = 2;

    for (int i=3; i<MAXP; i+=2) {
        if (primes[i] == 0) {
            for (int p = i; p<MAXP; p+=2*i)
                if(primes[p] == 0) primes[p] = i;
        }
    }

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

/*
    find all primes:

    vi alln(MAXP), primes;
    for (int i=2; i<MAXP; ++i) alln[i] = i;
    alln[1] = 0;

    for (int i=3; i<MAXP; i+=2) {
        if (alln[i]) {
            for (int p = i*3; p<MAXP; p+=2*i)
                alln[p] = 0;
        }
    }

    primes.pb(2);
    for (int i=3; i<MAXP; i+=2) if (alln[i]) primes.pb(i);

 */

/* bad TLE
const int MAXP = 1e6;

void solve(vi& primes) {
    int n, q; cin >> n >> q;
    int szp = (int)primes.size();

    auto f = [&] (int n) -> vpii {
        vpii nprime;
        for (int i=0; i<szp; ++i) {
            int p = primes[i];
            int count = 0;
            while (n % p == 0) {
                ++count;
                n /= p;
            }
            nprime.emplace_back(p, count);
        }
        return nprime;
    };

    vpii original = f(n);
    vpii nprime(original);


    while (q--) {
        int k; cin >> k;

        if (k == 2) {
            for (int i=0; i<szp; ++i)
                nprime[i] = original[i];

        } else if (k == 1) {
            int x; cin >> x;
            vpii primex = f(x);

            // computing d(n*x) and updating n
            int totd = 1;
            for (int i=0; i<szp; ++i) {
                nprime[i].s += primex[i].s;
                totd *= nprime[i].s + 1;
            }
            primex.clear();

            bool ok = true;
            vpii primed = f(totd);
            for (int i=0; i<szp; ++i) {
                if (primed[i].s > nprime[i].s)
                    ok = false;
            }

            if (ok) cout << "Yes\n";
            else cout << "No\n";
        }

    }

    cout << '\n';
}
 */