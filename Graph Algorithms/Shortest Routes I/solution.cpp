#include <bits/stdc++.h>
#define INF LLONG_MAX
#define ll long long
using namespace std;

const int mxN = 1e5;

void solveUsingDijsktraAlgo(int s, int n, vector<array<ll, 2>> (&adj)[mxN]) {

    vector<ll> d(n, INF);
    vector<ll> visited(n, 0);
    d[s] = 0;

    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        ll x = pq.top()[1]; pq.pop();
        if (visited[x]) continue;

        visited[x] = 1;
        for (auto v : adj[x]) {
            int y = v[0], w = v[1];
            if (d[x] + w < d[y]) {
                d[y] = d[x]+w;
                pq.push({d[y], y});
            }
        }
    }

    for (ll i : d) cout << i << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
//    vector<array<int, 3>> e;
    vector<array<ll, 2>> adj[mxN];

    for (int i = 0, x, y, w; i < m; i++) {
        cin >> x >> y >> w;
        x--, y--;
//        e.push_back({x, y, w});
        adj[x].push_back({y, w});
    }

//    solveUsingBellmanFordAlgo(0, n, e)
    solveUsingDijsktraAlgo(0, n, adj);

    return 0;
}
