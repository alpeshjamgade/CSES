#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

void DFS(int u, int pu, vector<int> (&adj)[mxN], vector<int> &visited, vector<int> &parent) {
    visited[u] = 1;
    parent[u] = pu;

    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v, u, adj, visited, parent);
        } else {
            if (v == pu) {
                continue;
            }
            else {
                int u2 = u;
                vector<int> ans;
                while (u^v) {
                    ans.emplace_back(u);
                    u = parent[u];
                }

                ans.push_back(v);
                ans.push_back(u2);

                cout << ans.size() << '\n';
                for (auto a : ans) {
                    cout << a+1 << ' ';
                }
                exit(0);
            }

        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> adj[mxN], visited(n, 0), parent(n, 0);


    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v; u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) DFS(i, -1, adj, visited, parent);
    }

    cout << "IMPOSSIBLE";

    return 0;
}
