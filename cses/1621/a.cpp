#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     unordered_set<int> s;
//     int n, c;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> c;
//         if (s.find(c) == s.end())
//             s.insert(c);
//     }

//     cout << s.size() << endl;
//     return 0;
// }

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    int count = 1, prev = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] > prev)
        {
            count++;
            prev = v[i];
        }

    cout << count << endl;
    return 0;
}