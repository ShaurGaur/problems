#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, c;
    cin >> n >> x;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (c <= x)
            v.push_back(c);
    }
    sort(v.begin(), v.end());

    int i = 0, j = n - 1, ans = 0;
    while (i < j)
    {
        if (v[i] + v[j] <= x)
            i++;
        j--;
        ans++;
    }
    if (i == j)
        ans++;

    cout << ans << endl;
    return 0;
}