#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

// got some help from https://codeforces.com/blog/entry/70018

int main()
{
    string a, b;
    cin >> a >> b;
    int na = a.length(), nb = b.length();
    vector<vector<int>> dp(na + 1, vector<int>(nb + 1, MOD));
    dp[0][0] = 0;

    for (int i = 0; i <= na; i++)
        for (int j = 0; j <= nb; j++)
        {
            if (i)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            if (j)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            if (i && j)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
        }

    cout << dp[na][nb] << endl;
    return 0;
}