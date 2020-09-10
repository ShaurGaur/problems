#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n >= 4 || n == 1)
    {
        int evenMax = (n / 2) * 2;
        int oddMax = (((n - 1) / 2) * 2) + 1;

        for (int i = 2; i <= evenMax; i += 2)
            cout << i << " ";
        for (int i = 1; i <= oddMax; i += 2)
            cout << i << " ";
        cout << endl;
    }
    else
        cout << "NO SOLUTION\n";

    return 0;
}