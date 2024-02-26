#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m, int k, vector<int> &desired_size, vector<int> &apartment_size) {
    sort(desired_size.begin(), desired_size.end());
    sort(apartment_size.begin(), apartment_size.end());

    int count = 0;
    for (int i = 0, j = 0; i < n && j < m;) {
        if (abs(desired_size[i]-apartment_size[j]) <= k) {
            count++;
            i++, j++;
        } else {
            if (desired_size[i] - apartment_size[j] > k) {
                j++;
            } else {
                i++;
            }
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired_size(n), apartment_size(m);
    for (int i = 0; i < n; i++) cin >> desired_size[i];
    for (int i = 0; i < m; i++) cin >> apartment_size[i];

    cout << solve(n, m, k, desired_size, apartment_size);
    return 0;
}
