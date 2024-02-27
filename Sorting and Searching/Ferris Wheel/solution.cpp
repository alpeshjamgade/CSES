#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> weights(n); 
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int count = 0;
    for (int i = 0, j = n-1; i <= j;) {
        if (weights[i] + weights[j] <= x) {
            count++;
            i++; j--;
        } else {
            count++;
            j--;
        }
    }

    cout << count;

    return 0;
}
