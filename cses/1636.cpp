#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define MOD 1000000007

int solve(vector<int> &v, int x, int n)
{
    sort(v.begin(), v.end());
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (!j)
                dp[i][j] = 1;
            else
            {
                int pick = (v[i] > j) ? 0 : dp[i][j - v[i]];
                int noPick = (i == 0) ? 0 : dp[i - 1][j];
                dp[i][j] = (pick + noPick) % MOD;
            }
        }
    }

    return dp[n - 1][x];
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << solve(v, x, n);
}