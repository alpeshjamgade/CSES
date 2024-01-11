#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

bool checkPath(int start, int end, map<int, set<int>> &adj, vector<int> &vis, vector<int> &p) {
    queue<int> qu;
    qu.push(start);
    vis[start] = 1;

    while (qu.size()) {
        int u = qu.front(); qu.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                p[v] = u;
                vis[v] = 1;
                qu.push(v);
            }
        }
    }

    return vis[end];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, x, y;
    cin >> n >> m;

    int a = 0, b = n-1;
    map<int, set<int>> adj;
    vector<int> p(mxN), vis(mxN, 0);

    for (int i = 0; i < m; i++) {
        cin >> x >> y; x--, y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    if (checkPath(0, n-1, adj, vis, p)) {
        vector<int> pathNodes;

        while (a != b) {
            pathNodes.emplace_back(b);
            b = p[b];
        }
        pathNodes.emplace_back(a);
        reverse(pathNodes.begin(), pathNodes.end());
        cout << pathNodes.size() << '\n';

        for (int x : pathNodes) {
            cout << x+1 << ' ';
        }
    }
    else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}
