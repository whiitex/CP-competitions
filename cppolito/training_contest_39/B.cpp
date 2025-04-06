#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

const int INF = 1e18;

struct Edge { int from, to, capacity, cost; };
vector<vector<int>> adj, cost, capacity;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF); d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

/*
 * @param N: number of nodes
 * @param edges: list of edges
 * @param K: desired flow
 * @param s: source
 * @param t: sink
 */
int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f, cost += f * d[t], cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    return flow < K ? -1 : cost;
}

void solve() {
    string target; cin >> target;
    int n; cin >> n;

    vi f(26); for (char c : target) ++f[c-'a'];

    int source = 0, sink = 1, node = 2;
    vector<Edge> edges;

    for (int i=0; i<26; ++i) { // 2:a, 3:b, 4:c, ..., 27:z
        edges.pb({node, sink, f[i], 0});
        ++node;
    }

    for (int i=0; i<n; ++i) {
        string s; int qt; cin >> s >> qt;
        edges.pb({source, node, qt, i+1});

        vi ff(26); for (char c : s) ++ff[c-'a'];
        for (int i=0; i<26; ++i) if (ff[i]) {
            edges.pb({node, 2+i, ff[i], 0});
        }

        ++node;
    }

    cout << min_cost_flow(node, edges, target.size(), source, sink);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}
