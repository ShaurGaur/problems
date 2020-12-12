#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

int partOne(unordered_set<int> &s, int t)
{
    auto it = s.begin();

    while (it != s.end())
    {
        if (s.find(t - *it) != s.end())
            return (*it * (t - *it));
        ++it;
    }
    return 0;
}

int partTwo(unordered_set<int> &s)
{
    auto it = s.begin();
    while (it != s.end())
    {
        int x = *it;
        unordered_set<int> v = s;
        v.erase(x);
        int a = partOne(v, 2020 - x);
        if (a)
            return x * a;
        ++it;
    }

    return 0;
}

int main()
{
    ifstream fin("input.txt", ios::in);
    unordered_set<int> v;
    int n, x;

    while (!fin.eof())
    {
        fin >> x;
        v.insert(x);
        n++;
    }

    cout << partOne(v, 2020) << " " << partTwo(v) << endl;

    return 0;
}