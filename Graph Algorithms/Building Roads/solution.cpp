#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

void DFS(int u, map<int, set<int>> &adj, vector<bool> &vis) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            DFS(v, adj, vis);
        }
    }
}

vector<int> countRoads(int n, map<int, set<int>> &adj, vector<bool> &vis) {
    vector<int> roads;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            DFS(i, adj, vis);
            roads.emplace_back(i);
        }
    }

    return roads;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n, m, a, b;
    cin >> n >> m;

    map<int, set<int>> adj;
    for (int i = 0; i < m; i++) {
        cin >> a >> b; a--, b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    vector<bool> vis(n, 0);
    vector<int> result = countRoads(n, adj, vis);

    cout << result.size()-1 << '\n';
    for (int i = 1; i < (int)result.size(); i++) {
        cout << result[0]+1 << ' ' << result[i]+1 << '\n';
    }
    return 0;
}
