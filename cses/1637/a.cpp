#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

void dfs(int n, vector<int> &dp)
{
    if (n < 10)
        dp[n] = 1;
    if (n <= 1 || dp[n] < 1000002)
        return;

    int ans = 1000002;
    string s = to_string(n);

    for (char c : s)
        if (c != '0')
        {
            int d = c - '0';
            dfs(n - d, dp);
            ans = min(ans, 1 + dp[n - d]);
        }

    dp[n] = ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1000002);
    dp[0] = 0;
    dfs(n, dp);
    cout << dp[n] << endl;
    return 0;
}