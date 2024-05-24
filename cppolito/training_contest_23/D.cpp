#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define f first
#define s second

int solve() {
    int n; cin >> n;
    vi tickets(n); for (int &i: tickets) cin >> i;
    int perca, a, percb, b, k;
    cin >> perca >> a >> percb >> b >> k;
    if (perca < percb) {
        swap(perca, percb);
        swap(a, b);
    }

    std::sort(tickets.begin(), tickets.end(), greater());

    vpii days;
    {
        int mcm = a * b / __gcd(a, b);
        for (int i = 1; i <= n; ++i) {
            if (i % mcm == 0) days.pb({i, 3});
            else if (i % b == 0 and b != a) days.pb({i, 1});
            else if (i % a == 0) days.pb({i, 2});
        }
    }
    int t=0, sum = 0;
    priority_queue<int> one, two;
    for (pii day: days) {

        if (day.s == 1) {
            sum += tickets[t] / 100 * percb;
            one.push(tickets[t]);
        }

        else if (day.s == 2) {
            if (!one.empty()) {
                int tickone = one.top(); one.pop();
                two.push(tickone);
                one.push(tickets[t]);

                sum -= tickone / 100 * percb;
                sum += tickets[t] / 100 * percb;
                sum += tickone / 100 * perca;
            } else {
                sum += tickets[t] / 100 * perca;
                two.push(tickets[t]);
            }
        }

        else if (day.s == 3) {

            if (!two.empty() and !one.empty()) {
                int ticktwo = two.top(); two.pop();
                int tickone = one.top(); one.pop();
                two.push(tickone);
                one.push(tickets[t]);

                sum -= ticktwo / 100 * perca;
                sum -= tickone / 100 * percb;

                sum += tickets[t] / 100 * percb;
                sum += tickone / 100 * perca;

                sum += ticktwo / 100 * (perca + percb);

            } else if (!two.empty()) {
                int ticktwo = two.top(); two.pop();
                two.push(tickets[t]);

                sum -= ticktwo / 100 * perca;
                sum += tickets[t] / 100 * perca;
                sum += ticktwo / 100 * (perca + percb);
            } else if (!one.empty()) {
                int tickone = one.top(); one.pop();
                one.push(tickets[t]);

                sum -= tickone / 100 * percb;
                sum += tickets[t] / 100 * percb;
                sum += tickone / 100 * (perca + percb);
            } else {
                sum += tickets[t] / 100 * (perca + percb);
            }

        }

        ++t;
        if (sum >= k) return day.f;
    }

    return -1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) cout << solve() << '\n';
}
