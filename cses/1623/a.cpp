#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> &v, int n)
{
    long long minSum = LLONG_MAX;

    for (unsigned long i = 0; i < (1 << (n - 1)); i++)
    {
        long long setOne = 0, setTwo = 0;
        int c = i;

        for (int j = n - 1; j >= 0; j--)
        {
            if (c % 2 == 1)
                setOne += v[j];
            else
                setTwo += v[j];
            c >>= 1;
        }

        long long diff = max(setOne, setTwo) - min(setTwo, setOne);
        minSum = min(minSum, diff);
    }

    return minSum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << solve(v, n) << endl;
    return 0;
}