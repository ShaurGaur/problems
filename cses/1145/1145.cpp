#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

int binSearch(vector<int> &v, int l, int r, int x)
{
    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        if (v[m] >= x)
            r = m;
        else
            l = m;
    }
    return r;
}

int main()
{
    int n, ans = 1, x, l = 1;
    cin >> n;
    vector<int> A(n, 0);
    vector<int> dp(n, 0);

    cin >> dp[0];

    for (int i = 1; i < n; i++)
    {
        cin >> x;
        if (x < dp[0])
            dp[0] = x;
        else if (x > dp[l - 1])
            dp[l++] = x;
        else
            dp[binSearch(dp, -1, l - 1, x)] = x;
    }

    cout << l << endl;
    return 0;
}