#include <bits/stdc++.h>
#define INF LLONG_MAX
#define ll long long
using namespace std;

const int mxN = 1e5;

ll SPFA(int s, int e, int n, vector<array<ll, 2>> (&adj)[mxN]) {
    vector<vector<ll>> d(n, {INF, INF});
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<>> pq;
    d[s] = {0, 0};
    pq.push({0, s, 0});

    while (!pq.empty()) {
        auto x = pq.top(); pq.pop();
        if (x[1] == e) break;
        if (x[0] != d[x[1]][x[2]]) continue;

        for (auto v : adj[x[1]]) {
            ll y = v[0], w = v[1];
            if (!x[2] && d[y][1] > d[x[1]][x[2]] + w/2) {
                d[y][1] = d[x[1]][x[2]] + w/2;
                pq.push({d[y][1], y, 1});
            }
            if (d[y][x[2]] > d[x[1]][x[2]] + w) {
                d[y][x[2]] = d[x[1]][x[2]] + w;
                pq.push({d[y][x[2]], y, x[2]});
            }

        }
    }

    return d[e][1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<array<ll, 2>> adj[mxN];
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c; a--, b--;
        adj[a].push_back({b, c});
    }

    cout << SPFA(0, n-1, n, adj);
    return 0;
}
