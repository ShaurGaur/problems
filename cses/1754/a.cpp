#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, a, b;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        cout << (!((a + b) % 3) && min(a, b) * 2 >= max(a, b) ? "YES" : "NO") << endl;
    }

    return 0;
}