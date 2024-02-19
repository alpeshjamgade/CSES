#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1;
    } else if (n <= 3) {
        cout << "NO SOLUTION";
    } else if (n == 4) {
      cout << "2 4 1 3";
    } else {
        for (int i = (n&1?n-1:n); i >= 2; i-=2) cout << i << ' ';
        for (int i = (n&1?n:n-1); i >= 1; i-=2) cout << i << ' ';
    }

    return 0;
}
