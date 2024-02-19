#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, x, prev, count = 0;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        cin >> x;

        if (prev > x) {
            count += prev-x;
        }
        prev = max(prev, x);
    }

    cout << count;
    return 0;
}
