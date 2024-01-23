    #include <bits/stdc++.h>

    using namespace std;

    void DFS(int node, int parent, vector<int> &subordinates, vector<vector<int>> &adj) {
        subordinates[node] = 1;

        for (int next : adj[node]) {
            DFS(next, node, subordinates, adj);
            subordinates[node] += subordinates[next];
        }
    }

    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int n, x;
        cin >> n;
        vector<vector<int>> adj(n);
        vector<int> subordinates(n);

        // relation data for employee 1 to n; 0th is boss.
        for (int i = 1; i < n; i++) {
            cin >> x; x--;
            adj[x].emplace_back(i);
        }

        DFS(0, -1, subordinates, adj);

        for (int c : subordinates) {
            cout << c-1 << ' ';
        }
        return 0;
    }
