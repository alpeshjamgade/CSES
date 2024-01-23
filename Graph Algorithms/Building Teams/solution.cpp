#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

void DFS(int u, int cu, int pu, vector<int> adj, vector<int> &visited, vector<int> &color, vector<int> &p) {
    visited[u] = 1;
    color[u] = cu;
    p[u] = pu;

    for (int v : adj[u]) {
        if (visited[v] and color[v] == cu) {
            cout << "IMPOSSIBLE";
            exit(0);
        }

        if (visited[v]) continue;

        DFS(v, cu^1, u, adj, visited, color, p);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> adj[mxN], visited(n, 0), color(n, 0), p(n);

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v; u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        DFS(i, 0, -1, adj, visited, color, p);
    }

    for (int i = 0; i < n; i++) {
        cout << color[i]+1 << ' ';
    }

    return 0;
}
