#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<int> tickets(n);
//     for (int i = 0; i < n; i++)
//         cin >> tickets[i];
//     sort(tickets.begin(), tickets.end());
//     vector<bool> taken(n, false);

//     vector<int> people(m);
//     for (int i = 0; i < m; i++)
//         cin >> people[i];

//     for (int p : people)
//     {
//         int curIdx = -1;
//         bool end = false;

//         for (int i = 0; i < n && !end; i++)
//             if (!taken[i])
//             {
//                 if (tickets[i] <= p)
//                     curIdx = i;
//                 else
//                     end = true;
//             }

//         if (curIdx >= 0)
//             taken[curIdx] = true;
//         cout << ((curIdx != -1) ? tickets[curIdx] : -1) << endl;
//     }

//     return 0;
// }

int main()
{
    int n, m, x;
    cin >> n >> m;
    multiset<int, greater<int>> tickets;

    while (n--)
    {
        cin >> x;
        tickets.insert(x);
    }

    while (m--)
    {
        cin >> x;
        auto it = tickets.lower_bound(x);
        if (it != tickets.end())
        {
            cout << *it << endl;
            tickets.erase(it);
        }
        else
            cout << "-1\n";
    }

    return 0;
}