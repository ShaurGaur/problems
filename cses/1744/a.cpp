#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

// int dfs(vector<vector<int>> &dp, int a, int b)
// {
//     if (a == b)
//         return 0;
//     // int ai = a - 1, bi = b - 1;
//     if (dp[a][b] != -1)
//         return dp[a][b];
//     int ans = MOD;
//     for (int i = 1; i < a; i++)
//         ans = min(ans, dfs(dp, i, b) + dfs(dp, a - i, b));
//     for (int i = 1; i < b; i++)
//         ans = min(ans, dfs(dp, a, i) + dfs(dp, a, b - i));
//     ans++;
//     dp[a][b] = ans;
//     return ans;
// }

int main()
{
    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
        {
            if (i != j)
            {
                int x = MOD;
                for (int y = 1; y < i; y++)
                    x = min(x, 1 + dp[y][j] + dp[i - y][j]);
                for (int y = 1; y < j; y++)
                    x = min(x, 1 + dp[i][y] + dp[i][j - y]);
                dp[i][j] = x;
            }
            else
                dp[i][j] = 0;
        }

    cout << dp[a][b] << endl;
    return 0;
}