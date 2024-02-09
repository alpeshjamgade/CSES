#include <bits/stdc++.h>

#define ll long long
#define INF INT_MAX
using namespace std;

const int mxN = 1e5;

void checkNegativeCycle(int n, set<array<ll, 3>> &edges) {
    vector<ll> d(n, INF), p(n, -1);
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        bool any = false;
        for (auto [x, y, w]: edges) {
            if (d[y] > d[x] + w) {
                d[y] = d[x] + w;
                p[y] = x;
                any = true;
                if (i == n) {
                    cout << "YES\n";
                    vector<ll> path;
                    vector<bool> visited(n, false);

                    // move y to start/end of the cycle.
                    while(!visited[y]) {
                        visited[y] = true;
                        y = p[y];
                    }

                    ll curr = y;
                    path.push_back(curr);
                    curr = p[curr];
                    while (curr ^ y) {
                        path.push_back(curr);
                        curr = p[curr];
                    }
                    path.push_back(curr);
                    reverse(path.begin(), path.end());
                    for (ll a: path) {
                        cout << a + 1 << ' ';
                    }
                    exit(0);
                }
            }
        }
        if (!any) break;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    set<array<ll, 3>> edges;
    for (int i = 0, x, y, w; i < m; i++) {
        cin >> x >> y >> w;
        x--, y--;
        edges.insert({x, y, w});
    }

    checkNegativeCycle(n, edges);
    return 0;
}