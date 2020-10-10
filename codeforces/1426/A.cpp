#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
using namespace std;

int main()
{
    int t, n, x, a = 0;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> x;
        if (n > 2)
        {
            n -= 2;
            a = 1 + (n / x);
            if (n % x > 0)
                a++;
        }
        else
            a = 1;
        cout << a << endl;
    }

    return 0;
}