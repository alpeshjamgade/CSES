#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

// DP : Iteration with Memo
int countGridPathIterDP(int n, int m, vector<string> &grid) {

    vector<vector<int>> DP(n, vector<int> (m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
           if (i == 0 && j == 0) {
               DP[i][j] = (grid[i][j] == '*'?0:1);
           }
           else {
               if (i == 0) {
                   DP[i][j] = (grid[i][j] == '*'?0:DP[i][j-1]);
               } else if (j == 0) {
                   DP[i][j] = (grid[i][j] == '*'?0:DP[i-1][j]);
               } else {
                   DP[i][j] = (grid[i][j] == '*'?0:(DP[i-1][j]%mod + DP[i][j-1]%mod)%mod);
               }
           }

        }
    }

    return DP[n-1][m-1];
}

// DP : Recursion with Memo

int countGridPathRecurDP(int n, int m, vector<string> &grid, vector<vector<int>> &DP) {

    if (DP[n][m] != -1)  return DP[n][m];

    if (n == 0 && m == 0 && grid[n][m] != '*') return 1;
     if ((n < 0 || m < 0) || grid[n][m] == '*') return 0;

    DP[n-1][m] = countGridPathRecurDP(n-1, m, grid, DP)%mod;
    DP[n][m-1] = countGridPathRecurDP(n, m-1, grid, DP)%mod;
    DP[n][m] = (DP[n-1][m] + DP[n][m-1])%mod;

    return DP[n][m];
}

int countGridPathRecurDP(int n, int m, vector<string> &grid) {
    vector<vector<int>> DP(n, vector<int> (m, -1));
    return countGridPathRecurDP(n, n, grid, DP);
}

// Plain Recursion
int countGridPathRecur(int n, int m, vector<string> &grid) {
    if (n == 0 && m == 0 && grid[n][m] != '*') return 1;
    if ((n < 0 || m < 0) || grid[n][m] == '*') return 0;

    return (countGridPathRecur(n-1, m, grid)%mod + countGridPathRecur(n, m-1, grid)%mod)%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<string> grid(n+1);
    vector<vector<int>> DP(n+1, vector<int> (n+1, 0));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    cout << countGridPathIterDP(n, n, grid);
    return 0;
}
