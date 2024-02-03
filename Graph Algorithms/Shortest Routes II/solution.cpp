#include <bits/stdc++.h>
#define INF 1e18
#define ll long long
using namespace std;

const int mxN = 500;

void solve(int n, vector<vector<ll>> &d) {
    for (int i = 0; i < n; i++) d[i][i] = 0;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> adj(n, vector<ll>(n, 0)), d(n, vector<ll>(n, INF));
    for (int i = 0, x, y, w; i < m; i++) {
        cin >> x >> y >> w; x--, y--;
        d[x][y] = min(d[x][y], (ll)w);
        d[y][x] = min(d[y][x], (ll)w);
    }

    solve(n, d);

    while(q--) {
        int x, y; cin >> x >> y; x--, y--;
        cout << ((d[x][y]>=INF)?-1:d[x][y]) << endl;
    }
    return 0;
}
