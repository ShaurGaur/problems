#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main()
{
    ull r;
    cin >> r;

    cout << 0 << endl;
    if (r >= 2)
        cout << 6 << endl;

    for (ull n = 3; n <= r; n++)
    {
        ull comb = ((n * n) * (n * n - 1)) / 2;
        ull bads = 4 * (n - 1) * (n - 2);
        ull ans = comb - bads;
        cout << ans << endl;
    }
    return 0;
}