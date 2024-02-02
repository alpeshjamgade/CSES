#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e4, di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};
const char dn[4] = {'D', 'R', 'U', 'L'};
int n, m, si, sj, d[mxN][mxN];
string adj[mxN];

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && adj[i][j] == '.';
}

void BFS(string (&adj)[mxN], vector<array<int, 2>> &monsters) {
    queue<array<int, 2>> qu;

    for (auto monster: monsters) {
        qu.push({monster[0], monster[1]});
    }

    qu.push({si, sj});
    d[si][sj] = -1;

    while (!qu.empty()) {
        array<int, 2> u = qu.front();
        qu.pop();

        if (adj[u[0]][u[1]] == 'A' && (u[0] == 0 || u[0] == n - 1 || u[1] == 0 || u[1] == m - 1)) {
            cout << "YES\n";

            string path;
            int dx = u[0], dy = u[1];

            while (d[dx][dy] != -1) {
                path += dn[d[dx][dy]];
                int dd = d[dx][dy] ^ 2;
                dx += di[dd];
                dy += dj[dd];
            }

            reverse(path.begin(), path.end());
            cout << path.size() << endl << path;
            return;
        }
        for (int k = 0; k < 4; k++) {
            int vi = u[0] + di[k], vj = u[1] + dj[k];
            if (isValid(vi, vj)) {
                qu.push({vi, vj});
                adj[vi][vj] = adj[u[0]][u[1]];
                if (adj[u[0]][u[1]] == 'A') {
                    d[vi][vj] = k;
                }
            }
        }
    }

    cout << "NO\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<array<int, 2>> monsters;
    for (int i = 0; i < n; i++) {
        cin >> adj[i];
        for (int j = 0; j < m; j++) {
            if (adj[i][j] == 'M') {
                monsters.push_back({i, j});
            } else if (adj[i][j] == 'A') {
                si = i, sj = j;
            }
        }
    }

    BFS(adj, monsters);
    return 0;
}
