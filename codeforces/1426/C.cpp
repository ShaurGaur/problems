#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
using namespace std;

int solve(int n, vector<int> &dp)
{
    // each move is a choice between incrementing a[0] or duplicating a[0]
    int maxVal = 1;

    for (int i = 2; i <= n; i++)
    {
        if (dp[i] == -1)
        {
            dp[i] = min(dp[max(2, i - a[0])], dp[i - 1]) + 1;
            if (dp[i - a[0]] < dp[i - 1])
                a.push_back(a[0]);
            else
                a[0]++;

            // cout << "i: " << i << " { ";
            // for (int num : a)
            //     cout << num << " ";
            // cout << "}\n";
        }
    }

    return dp[n];
}

int main()
{
    int t, n;
    cin >> t;
    vector<int> dp(MOD, -1);
    dp[1] = 0;
    dp[0] = 0;
    dp[2] = 1;
    vector<int> ans;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        // cout << solve(n, dp) << endl;
        ans.push_back(solve(n, dp));
    }

    // for (int d : dp)
    //     cout << d << " ";
    // cout << endl;

    for (int a : ans)
        cout << a << " ";
    cout << endl;

    return 0;
}