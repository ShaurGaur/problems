#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

ll foo(vector<ll> &v, ll target, ll k)
{
    vector<ll> temp(k, 0);
    ll sum = 0;

    for (int i = 0; i < k; i++)
    {
        temp[i] = v[i];
        sum += v[i];
    }

    for (int i = k; i < v.size() && sum != target; i++)
    {
        sum -= temp[i % k];
        sum += v[i];
        temp[i % k] = v[i];
    }

    if (sum == target)
    {
        ll hi = LLONG_MIN, lo = LLONG_MAX;
        for (ll i : temp)
        {
            hi = max(hi, i);
            lo = min(lo, i);
        }
        return hi + lo;
    }
    else
        return 0;
}

int main()
{
    ifstream fin("input.txt", ios::in);
    queue<ll> q;
    unordered_set<ll> s;
    ll temp, ans;
    vector<ll> v;

    while (!fin.eof())
    {
        while (q.size() < 25)
        {
            fin >> temp;
            q.push(temp);
            s.insert(temp);
            v.push_back(temp);
        }

        fin >> temp;
        bool good = false;
        for (auto it = s.begin(); it != s.end() && !good; ++it)
            if (s.find(temp - *it) != s.end())
                good = true;

        if (!good)
        {
            cout << "part 1: " << temp << endl;
            ans = temp;
        }

        s.erase(q.front());
        q.pop();
        q.push(temp);
        s.insert(temp);
        v.push_back(temp);
    }

    int k = 2;
    bool found = false;
    while (!found)
    {
        ull maybe = foo(v, ans, k);
        if (maybe > 0)
        {
            found = true;
            cout << "part 2: " << maybe << endl;
        }
        else
            k++;
    }

    return 0;
}