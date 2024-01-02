#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6;
const int mod = 1e9+7;

void calculateDiceCombinations(int n, vector<int>& dp) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, 6); j++) {
            dp[i] = (dp[i] + dp[i-j]) % mod ;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> dp(mxN, 0);

    dp[0] = 1;
    calculateDiceCombinations(n, dp);

    cout << dp[n] << '\n';

    return 0;
}
