/**
 * @file weird_algorithm.cpp
 * @author Alpesh Jamgade (alpeshjamgade21@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first
#define se second
#define pi 3.1415926535
#define mod1 1000000007
#define mod2 1000000009
#define mp make_pair
#define no_of_digits(n) floor(log10(n)) + 1
#define lcm(a, b) (a / __gcd(a, b) * b)
#define sdebug(n) cout << "\n' n = " << n << " '\n";

using namespace std;

void solve()
{
    int n;
    cin >> n;

    cout << n << ' ';
    while (n != 1)
    {
        n = n & 1 ? n / 2 : n * 3 + 1;
        cout << n << ' ';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
