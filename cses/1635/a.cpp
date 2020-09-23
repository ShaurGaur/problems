#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= x; i++)
        for (int c : coins)
            if (i - c >= 0)
                dp[i] = (dp[i] + dp[i - c]) % MOD;

    cout << dp[x] << endl;
    return 0;
}