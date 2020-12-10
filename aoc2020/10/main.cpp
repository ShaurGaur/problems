#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

ll partTwo(vector<ll> &v)
{
    ll ans = 1;
    vector<vector<ll>> groups = {{v[0]}};
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] - v[i - 1] >= 3)
            groups.push_back({v[i]});
        else
            groups.back().push_back(v[i]);
    }

    for (auto g : groups)
        if (g.size() > 2)
        {
            ll vars = 0, diff = g.back() - g[0];
            if (diff <= 3)
                vars = (1 << (g.size() - 2));
            else if (diff == 4)
                vars = 7;
            ans *= vars;
        }

    return ans;
}

int main()
{
    ifstream fin("input.txt", ios::in);
    ll temp;
    vector<ll> v = {0};

    while (!fin.eof())
    {
        fin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    v.push_back(v.back() + 3);
    ll n = v.size(), j = 0;
    vector<ll> d(4);

    for (int i = 0; i < v.size(); i++)
    {
        d[v[i] - j]++;
        j = v[i];
    }

    cout << "p1: " << d[1] * d[3] << endl;
    cout << "p2: " << partTwo(v) << endl;

    return 0;
}