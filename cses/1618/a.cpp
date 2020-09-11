#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main()
{
    ull n;
    cin >> n;
    bool zeroFound = false;
    ull ans = 0, div = 5;

    while (!zeroFound)
    {
        ull quotient = n / div;
        if (quotient == 0)
            zeroFound = true;
        else
            div *= 5;
        ans += quotient;
    }

    cout << ans << endl;
    return 0;
}