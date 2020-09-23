#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0, m = 0, k = 0, ans = 0, i = 0, j = 0;
    cin >> n >> m >> k;

    vector<int> people(n);
    for (int i = 0; i < n; i++)
        cin >> people[i];
    sort(people.begin(), people.end());

    vector<int> rooms(m);
    for (int i = 0; i < m; i++)
        cin >> rooms[i];
    sort(rooms.begin(), rooms.end());

    while (i < n && j < m)
    {
        if (people[i] + k < rooms[j])
            i++;
        else if (people[i] - k > rooms[j])
            j++;
        else
        {
            i++;
            j++;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}