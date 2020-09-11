#include <bits/stdc++.h>
#define ull unsigned long long
#define MOD 1000000007
using namespace std;

int solve(int n)
{
    int ans = 1;
    n -= 29;
    ans <<= 29;
    for (int i = 0; i < n; i++)
        ans = (ans << 1) % MOD;
    return ans;
}

int main()
{
    int n, ans;
    cin >> n;

    if (n <= 29)
    {
        ans = 1;
        ans <<= n;
    }
    else
        ans = solve(n);
    cout << ans << endl;

    return 0;
}