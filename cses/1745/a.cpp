#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

int main()
{
    int n, max = 0;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
        max += coins[i];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(max + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= max; j++)
            dp[i][j] = dp[i - 1][j] || ((j - coins[i - 1]) >= 0 && dp[i - 1][j - coins[i - 1]]);

    vector<int> ans;
    for (int j = 1; j <= max; j++)
        if (dp[n][j])
            ans.push_back(j);
    cout << ans.size() << endl;
    for (int a : ans)
        cout << a << " ";
    cout << endl;

    return 0;
}