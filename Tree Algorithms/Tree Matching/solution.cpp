//
// Created by Alpesh Jamgade on 13/2/24.
//
#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

void DFS(int u, int p, int &count, vector<int>(&adj)[mxN], vector<bool> &visited) {
    for(int v : adj[u]) {
        if (v == p) continue;
        DFS(v, u, count, adj, visited);
        if (!visited[u] && !visited[v]) {
            count++;
            visited[u]=true;
            visited[v]=true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> adj[mxN];
    vector<bool> visited(n, 0);

    for (int i = 0, x, y; i < n-1; i++) {
        cin >> x >> y; x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int count = 0;
    DFS(0, -1, count, adj, visited);
    cout << count;
    return 0;
}
