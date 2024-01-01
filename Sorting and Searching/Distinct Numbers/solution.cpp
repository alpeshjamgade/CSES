#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int  uniqueCount = 0, prev = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] != prev) {
            uniqueCount++;
        }
        prev = arr[i];
    }

    cout << uniqueCount;
    return 0;
}
