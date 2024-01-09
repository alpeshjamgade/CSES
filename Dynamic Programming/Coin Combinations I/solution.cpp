#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e9;
const int mod = 1e9+7;

int coinCombinations(int target, vector<int> &coins, vector<int> &DP) {
    DP[0] = 1;

    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
                DP[i] = (DP[i] + DP[i - coins[j]]) % mod;
            }
        }
    }

    return DP[target];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n), DP(x, 0);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << coinCombinations(x, coins, DP);
    return 0;
}
