#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<char> singles;
    stack<char> doubles;
    string ans = "", s = "";
    cin >> s;

    for (char c : s)
    {
        if (singles.find(c) != singles.end())
        {
            ans.push_back(c);
            singles.erase(c);
            doubles.push(c);
        }
        else
            singles.insert(c);
    }

    if (singles.size() > 1)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }

    if (!singles.empty())
        ans.push_back(*(singles.begin()));

    while (!doubles.empty())
    {
        ans.push_back(doubles.top());
        doubles.pop();
    }

    cout << ans << endl;
    return 0;
}