#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n;
    ll res = 0;
    for (int i = 0; i < n-1; i++) {
        cin >> x;
        res ^= x;
    }
    for (int i = 1; i <= n; i++) {
        res ^= i;
    }

    cout << res;
    return 0;
}
