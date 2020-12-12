#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

int main()
{
    string temp;
    ifstream fin("input.txt", ios::in);
    ull a = 0;
    vector<bool> ids(8 * 128, false);

    while (!fin.eof())
    {
        fin >> temp;
        ull minrow = 0, maxrow = 128, mincol = 0, maxcol = 8;

        for (int i = 0; i < 7; i++)
        {
            int half = (maxrow - minrow) / 2;
            if (temp[i] == 'F')
                maxrow -= half;
            else
                minrow += half;
        }

        for (int i = 7; i < 10; i++)
        {
            int half = (maxcol - mincol) / 2;
            if (temp[i] == 'L')
                maxcol -= half;
            else
                mincol += half;
        }

        ull id = minrow * 8 + mincol;
        ids[id] = true;
        a = max(a, id);
    }

    std::cout << "part 1: " << a << endl;

    bool found = false;
    for (int i = 1; i < (128 * 8) && !found; i++)
    {
        if (!ids[i] && ids[i - 1] && ids[i + 1])
        {
            std::cout << "part 2: " << i << endl;
            found = true;
        }
    }

    return 0;
}