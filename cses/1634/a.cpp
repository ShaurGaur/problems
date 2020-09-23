#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

void dfs(vector<int> &dp, vector<int> &coins, int x)
{
    if (x < 0 || dp[x] <= x)
        return;
    int ans = x + 1;
    for (int c : coins)
        if (x - c >= 0)
        {
            dfs(dp, coins, x - c);
            if (dp[x - c] < ans && dp[x - c] >= 0)
                ans = dp[x - c];
        }
    dp[x] = ans <= x ? ans + 1 : -1;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    vector<int> dp(x + 1, x + 1);
    dp[0] = 0;
    dfs(dp, coins, x);
    cout << dp[x] << endl;
    return 0;
}
