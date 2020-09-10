#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull solve(ull y, ull x)
{
    ull dist = min(y, x) - 1;
    ull root = max(y, x);
    bool ltr = root % 2;
    bool atEnd = (ltr && x > y) || (!ltr && y > x);

    ull square = (!atEnd) ? (root - 1) * (root - 1) : root * root;
    ull ans = (!atEnd) ? square + dist + 1 : square - dist;
    return ans;
}

int main()
{
    ull t, y, x;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> y >> x;
        cout << solve(y, x) << endl;
    }

    return 0;
}