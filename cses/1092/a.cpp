#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << ((n % 4 == 1 || n % 4 == 2) ? "NO" : "YES") << endl;
    if (n % 4 == 1 || n % 4 == 2)
        return 0;

    vector<int> first;
    vector<int> second;
    int i = 0;

    if (n % 4 == 3)
    {
        first.push_back(++i);
        first.push_back(++i);
        second.push_back(++i);
    }

    while (i < n)
    {
        first.push_back(++i);
        second.push_back(++i);
        second.push_back(++i);
        first.push_back(++i);
    }

    cout << first.size() << endl;
    for (int f : first)
        cout << f << " ";
    cout << endl;

    cout << second.size() << endl;
    for (int f : second)
        cout << f << " ";
    cout << endl;

    return 0;
}