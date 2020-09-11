#include <bits/stdc++.h>
using namespace std;

void recur(string cur, string left, set<string> &ans)
{
    if (!left.length())
    {
        ans.insert(cur);
        return;
    }

    for (int i = 0; i < left.length(); i++)
        recur(cur + left[i], left.substr(0, i) + left.substr(i + 1), ans);
}

int main()
{
    string s;
    cin >> s;
    set<string> ans;
    recur("", s, ans);
    cout << ans.size() << endl;
    for (auto a : ans)
        cout << a << endl;
    return 0;
}
