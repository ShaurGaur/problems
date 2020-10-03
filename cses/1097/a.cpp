#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
using namespace std;

// help from https://codeforces.com/blog/entry/70018

int main()
{
    ll n, ans, sum = 0;
    cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        sum += x[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for (int i = n - 1; i >= 0; i--)
        for (int j = i; j < n; j++)
            dp[i][j] = (i == j) ? x[i] : max(x[i] - dp[i + 1][j], x[j] - dp[i][j - 1]);

    ans = (sum + dp[0][n - 1]) / 2;
    cout << ans << endl;
    return 0;
}