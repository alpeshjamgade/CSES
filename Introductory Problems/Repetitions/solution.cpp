#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int mxCount = INT_MIN, count = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i-1]) {
            count++;
        } else {
            mxCount = max(count, mxCount);
            count = 1;
        }
    }

    mxCount = max(count, mxCount);

    cout << mxCount;

    return 0;
}
