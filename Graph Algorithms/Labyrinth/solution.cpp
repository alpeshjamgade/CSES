#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e3, di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};
const char dn[4] = {'D', 'R', 'U', 'L'};
int n, m, si, sj, ei, ej, d[mxN][mxN];
string adj[mxN], p[mxN];

bool isValid(int i, int j) {
    return i>=0 && i < n && j >= 0 && j < m && adj[i][j] != '#';
}

void BFS(int si, int sj) {
   queue<array<int, 2>> qu;
   qu.push({si, sj});
   adj[si][sj] = '#';

   while (qu.size()) {
        array<int, 2> u = qu.front();
        qu.pop();
        for (int k = 0; k < 4; k++) {
            int vi = u[0]+di[k], vj = u[1]+dj[k];
            if (isValid(vi, vj)) {
                qu.push({vi, vj});
                p[vi][vj] = dn[k];
                d[vi][vj] = k;
                adj[vi][vj] = '#';
            }
        }
   }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> adj[i][j];
            if (adj[i][j] == 'A') {
                si = i, sj = j;
            } else if (adj[i][j] == 'B') {
                ei = i, ej = j;
            }
        }
    }

    BFS(si, sj);

    if (p[ei][ej] != 'B') {
        cout << "YES\n";

       // backtrack the path.
       string path = "";
       while(ei^si || ej^sj) {
            path += p[ei][ej];
            int dd = d[ei][ej]^2;  // select direction opposite to what it took to come to ei, ej
            ei += di[dd];
            ej += dj[dd];
       }

       reverse(path.begin(), path.end());
       cout << path.size() << '\n';
       cout << path << '\n';

    } else {
        cout << "NO\n";
    }

    return 0;
}
