#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> prices(n, 0);
    vector<int> pages(n, 0);
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    vector<int> dp(x + 1, 0);
    for (int j = 0; j < n; j++)
        for (int i = x; i >= 1; i--)
            if (prices[j] <= i)
                dp[i] = max(dp[i], pages[j] + dp[i - prices[j]]);

    cout << dp[x] << endl;
    return 0;
}