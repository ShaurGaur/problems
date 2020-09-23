#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    if (grid[n - 1][n - 1] == '*')
    {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 1; i < n; i++)
        if (grid[0][i] != '*' && dp[0][i - 1] && grid[0][i - 1] != '*')
            dp[0][i] = 1;
    for (int i = 1; i < n; i++)
        if (grid[i][0] != '*' && dp[i - 1][0] && grid[i - 1][0] != '*')
            dp[i][0] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            if (grid[i][j] != '*')
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;

    cout << dp[n - 1][n - 1] << endl;
    return 0;
}