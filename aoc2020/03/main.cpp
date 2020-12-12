#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

int ans(vector<string> &v, int x, int y = 1)
{
    int a = 0, n = v.size(), m = v[0].length(), l = x;
    for (int i = y; i < n; i += y)
    {
        if (v[i][l % m] == '#')
            a++;
        l += x;
    }
    return a;
}

int main()
{
    ifstream fin("input.txt", ios::in);
    vector<string> v;
    while (!fin.eof())
    {
        string s;
        fin >> s;
        v.push_back(s);
    }

    vector<int> a = {
        ans(v, 1, 1),
        ans(v, 3, 1),
        ans(v, 5, 1),
        ans(v, 7, 1),
        ans(v, 1, 2)};

    ull answer = 1;
    for (int i : a)
        answer *= i;
    cout << answer << endl;

    return 0;
}