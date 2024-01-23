#include <bits/stdc++.h>

using namespace std;

vector<int> getDigits(int n) {
    vector<int> digits;
    while (n) {
        digits.emplace_back(n%10);
        n /= 10;
    }

    return digits;
}

int calculate(int n) {
    vector<int> DP(n+1, INT_MAX);
    DP[0] = 0;

    for (int i = 1; i <= n; i++) {
        auto digits = getDigits(i);
        for (int d : digits) {
            if (d != 0) {
              DP[i] = min(DP[i], 1 + DP[i-d]);
            }
        }
    }

    return DP[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;

    cout <<calculate(n) << '\n';

    return 0;
}
