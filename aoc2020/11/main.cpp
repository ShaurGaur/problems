#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

int main()
{
    ifstream fin("input.txt", ios::in);
    vector<string> seats;
    string temp;

    while (!fin.eof())
    {
        fin >> temp;
        seats.push_back(temp);
    }

    vector<string> old;
    bool same = false;
    do
    {
        old.resize(0);
        for (int i = 0; i < seats.size(); i++)
            old.push_back(seats[i]);

        for (int i = 0; i < seats.size(); i++)
        {
            for (int j = 0; j < seats[0].size(); j++)
            {
                int occupied = 0;
                vector<pair<int, int>> neighbors = {
                    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}};

                for (pair<int, int> p : neighbors)
                {
                    bool found = false;
                    int ix = i + p.first, jx = j + p.second;

                    // Part 1 code.
                    // if (ix >= 0 && jx >= 0 && ix < seats.size() && jx < seats[0].size() && old[ix][jx] == '#')
                    //     occupied++;

                    // Part 2 code.
                    while (ix >= 0 && jx >= 0 && ix < seats.size() && jx < seats[0].size() && !found)
                    {
                        if (seats[ix][jx] == '.')
                        {
                            ix += p.first;
                            jx += p.second;
                        }
                        else
                        {
                            found = true;
                            if (old[ix][jx] == '#')
                                occupied++;
                        }
                    }
                }

                if (occupied == 0 && seats[i][j] == 'L')
                    seats[i][j] = '#';
                else if (seats[i][j] == '#' && occupied >= 5) // change to 4 for part 1.
                    seats[i][j] = 'L';
            }
        }

        same = true;
        for (int i = 0; i < seats.size() && same; i++)
            if (seats[i] != old[i])
                same = false;
    } while (!same);

    int occupied = 0;
    for (string s : seats)
        for (char c : s)
            if (c == '#')
                occupied++;
    cout << occupied << endl;

    return 0;
}
