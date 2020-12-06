#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

void printSet(set<char> &s)
{
    for (auto it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    ifstream fin("input.txt", ios::in);
    set<char> s;
    string temp;
    ull ans = 0;
    bool first = true;

    while (!fin.eof())
    {
        getline(fin, temp);

        if (temp == "")
        {
            ans += s.size();
            s.clear();
            first = true;
        }

        else
        {
            if (first)
            {
                for (char c : temp)
                    s.insert(c);
                first = false;
            }
            else
            {
                set<char> t;
                for (char c : temp)
                    t.insert(c);

                vector<char> v(s.size());
                auto it = set_intersection(
                    s.begin(), s.end(),
                    t.begin(), t.end(),
                    v.begin());
                v.resize(it - v.begin());
                set<char> r(v.begin(), v.end());
                s = r;
            }
        }
    }

    if (!s.empty())
        ans += s.size();

    cout << ans << endl;

    return 0;
}