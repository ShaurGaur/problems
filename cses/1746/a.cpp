#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

// got some help from https://codeforces.com/blog/entry/70018

void dpUpdate(vector<vector<int>> &dp, int i, int x)
{
    vector<int> options = {x - 1, x, x + 1};
    int m = dp[0].size() - 1;
    for (int o : options)
        if (o >= 1 && o <= m)
            dp[i][x] = (dp[i][x] + dp[i - 1][o]) % MOD;
}

int main()
{
    int n, m, x, ans = 0;
    cin >> n >> m >> x;
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    dp[0][x] = 1;
    if (x == 0)
        for (int i = 0; i <= m; i++)
            dp[0][i] = 1;

    for (int i = 1; i < n; i++)
    {
        cin >> x;
        if (x == 0)
            for (int j = 1; j <= m; j++)
                dpUpdate(dp, i, j);
        else
            dpUpdate(dp, i, x);
    }

    for (int i = 1; i <= m; i++)
        ans = (ans + dp[n - 1][i]) % MOD;
    cout << ans << endl;
    return 0;
}