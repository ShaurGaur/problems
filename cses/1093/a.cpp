#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
using namespace std;

int main()
{
    int n, t;
    cin >> n;
    if (n % 4 == 1 || n % 4 == 2)
    {
        cout << 0 << endl;
        return 0;
    }
    t = n * (n + 1) / 4;
    vector<vector<int>> dp(n, vector<int>(t + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 0; j <= t; j++)
            dp[i][j] = (dp[i - 1][j] + (j >= i ? dp[i - 1][j - i] : 0)) % MOD;

    cout << dp[n - 1][t] << endl;
    return 0;
}