#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e9;

int countMinCoins(int sum, vector<int> &coins, vector<int> &DP) {
    int n = coins.size();
    DP[0] = 0;
    for (int i = 1; i <= sum; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                DP[i] = min(DP[i], DP[i - coins[j]] + 1);
            }
        }
    }

    return (DP[sum] == mxN?-1:DP[sum]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n), DP(x+1, mxN);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << countMinCoins(x, coins, DP);
    return 0;
}
