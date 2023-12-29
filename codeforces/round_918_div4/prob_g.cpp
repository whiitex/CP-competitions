#include <bits/stdc++.h>

using namespace std;

#define lll __ll128_t
#define ll long long
#define ld long double
#define f first
#define s second
typedef pair<int,int> pii;

const ll MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

struct Node {
    int i;
    int cost;
    int bike;
    vector<Node*> children;
    Node(int index, int c) {
        i = index;
        cost = c;
    }
};

void solve() {
    int n,m; cin >> n >> m;
    vector<pii> roads[n+1];
    vector<int> bike(n+1);
    for (int i=0; i<m; ++i) {
        int u,v,w; cin >> u >> v >> w;
        roads[u].emplace_back(v,w);
        roads[v].emplace_back(u,w);
    }
    for (int i=1; i<=n; ++i) cin >> bike[i];

    vector<vector<ll>> dp(n+1, vector<ll>(1001, LONG_LONG_MAX));
    dp[1][bike[1]] = 0;
    vector<vector<bool>> visited(n+1, vector<bool>(1001, false));

    priority_queue<array<ll,3>, vector<array<ll,3>>, greater<>> q;
    q.push({0, 1, bike[1]});

    while (!q.empty()) {

        int now = q.top()[1];
        int bk = q.top()[2];
        q.pop();

        if (visited[now][bk] or dp[now][bk] == LONG_LONG_MAX) continue;
        visited[now][bk] = true;

        for (auto ch: roads[now]) {
            ll nextcost = dp[now][bk] + 1ll * ch.second * bk;
            ll minbike = min(bk, bike[ch.first]);

            if (!visited[ch.first][minbike]) {
                // avoiding same pair of city link
                if (dp[ch.first][minbike] > nextcost) {
                    dp[ch.first][minbike] = nextcost;
                    q.push({nextcost, ch.first, minbike});
                }
            }
        }

    }

    ll ans = LONG_LONG_MAX;
    for (int i=1; i<=1000; ++i) ans = min (ans, dp[n][i]);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}




/* MEMORY LIMIT EXCEEDED
 * void solve() {
    int n,m; cin >> n >> m;
    vector<Node*> cities(n+1);
    int road[n+1][n+1];
    for (int i=0; i<=n; ++i) for (int j=0; j<=n; ++j) road[i][j] = INT32_MAX;

    for (int i=1; i<=n; ++i) cities[i] = new Node(i,INT32_MAX);

    for (int i=0; i<m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        cities[u]->children.push_back(cities[v]);
        cities[v]->children.push_back(cities[u]);
        road[u][v] = min (road[u][v], w);
        road[v][u] = min (road[v][u], w);
    }

    vector<vector<ll>> dp(n+1);
    bool visited[n+1][1001]; memset(visited, false, sizeof(visited));
    for (int i=1; i<=n; ++i) dp[i].resize(1001, LONG_LONG_MAX);
    for (int i=1; i<=n; ++i) cin >> cities[i]->bike;

    priority_queue<array<ll,3>> q;
    int bk1 = cities[1]->bike;
    for (auto ch: cities[1]->children)
        q.push({-road[1][ch->i] * bk1, bk1,ch->i });

    while (!q.empty()) {

        ll dest = q.top()[2];
        Node* Dest = cities[q.top()[2]];
        ll bike = q.top()[1];
        ll ct = -q.top()[0];
        q.pop();

        // update dp
        dp[dest][bike] = min(ct, dp[dest][bike]);
        visited[dest][bike] = true;

        // add children
        ll newbike = min((int)bike, Dest->bike);
        if (dest!=n) for (auto ch: Dest->children) if (!visited[ch->i][newbike]) {
            ll cost = dp[dest][bike] + (ll)road[ch->i][Dest->i] * newbike;
            q.push({-cost, newbike,ch->i});
        }

    }

    ll ans = LONG_LONG_MAX;
    for (int i=1; i<=1000; ++i) ans = min(ans, dp[n][i]);
    cout << ans << '\n';
}
 */

/* NOT WORKING DIJKSTRA
 *
void solve() {
    ll n,m; cin >> n >> m;
    vector<Node*> cities(n+1);
    map<pair<ll,ll>, ll> road;
    map<pair<int,int>,int> visited;
    for (ll i=0; i<=n; ++i) cities[i] = new Node(i,LONG_LONG_MAX);

    for (ll i=0; i<m; ++i) {
        ll u, v, w; cin >> u >> v >> w;
        if (u > v) swap(u,v);
        if (road.find({u,v}) == road.end()) {
            cities[u]->children.push_back(cities[v]);
            cities[v]->children.push_back(cities[u]);
            road[{u,v}] = w;
            visited.insert({{u,v},0});
        } else road[{u,v}] = min(road[{u,v}], w);
    }

    for (ll i=1; i<=n; ++i) cin >> cities[i]->bike;

//    bool visited[n+1];
//    memset(visited, false,  sizeof(visited));
//    visited[0] = true;
//    priority_queue<pii, vector<pii>, greater<>> q;

    queue<pii> q;
    q.push({{LONG_LONG_MAX,0},{0,1}});

    ll ans = LONG_LONG_MAX;
    while (!q.empty()) {
        Node* sour = cities[q.front().second.first];
        Node* dest = cities[q.front().second.second];
        ll costo = q.front().first.second;
        ll smallbike = min(dest->bike, q.front().first.first);
        q.pop();

//        if (sour->i != 0) dest->bike = min(dest->bike, sour->bike);

        dest->cost = costo;
        if (dest->i == n) ans = min(ans, dest->cost);

        visited[{min(sour->i, dest->i), max(sour->i, dest->i)}]++;

        for(Node* ch: dest->children) {
             pair<ll,ll> sourdest = {dest->i, ch->i};
             ll cs = dest->cost + smallbike * road[{min(ch->i, dest->i), max(ch->i, dest->i)}];
             if (visited[{min(ch->i, dest->i), max(ch->i, dest->i)}] < 50) {
                 q.push({{smallbike,cs}, sourdest});
//                 visited[{min(ch->i, dest->i), max(ch->i, dest->i)}]++;
             }
        }

    }

    cout << ans << '\n';
}
 */
