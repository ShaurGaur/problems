#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

struct instr
{
    string type;
    long diff;
    bool visited;
};

ll run(vector<instr> v)
{
    ll i = 0, acc = 0;
    while (!v[i].visited && i < v.size())
    {
        if (v[i].type == "acc")
            acc += v[i].diff;
        v[i].visited = true;

        if (v[i].type == "jmp")
            i = i + v[i].diff;
        else
            i++;
    }
    return acc;
}

bool good(vector<instr> v)
{
    ll i = 0, acc = 0;
    while (i < v.size() && !v[i].visited)
    {
        if (v[i].type == "acc")
            acc += v[i].diff;
        v[i].visited = true;

        if (v[i].type == "jmp")
            i = i + v[i].diff;
        else
            i++;
    }

    return (i == v.size());
}

ull countVisited(vector<instr> &v)
{
    ull ans = 0;
    for (instr i : v)
        ans += i.visited;
    return ans;
}

int main()
{
    ifstream fin("input.txt", ios::in);
    string temp;
    ll acc = 0;
    vector<instr> v;

    while (!fin.eof())
    {
        getline(fin, temp);
        instr in;
        in.type = temp.substr(0, 3);
        in.diff = stoul(temp.substr(5));
        if (temp[4] == '-')
            in.diff *= -1;
        in.visited = false;
        v.push_back(in);
    }

    cout << "p1: " << run(v) << endl;

    bool gg = false, acc2 = 0;
    for (int j = 0; j < v.size() && !gg; j++)
    {
        vector<instr> w = v;
        temp = w[j].type;
        bool cont = true;

        if (temp == "nop")
            w[j].type = "jmp";
        else if (temp == "jmp")
            w[j].type = "nop";
        else
            cont = false;

        if (cont)
        {
            gg = good(w);
            if (gg)
                cout << "p2: " << run(w) << endl;
        }
    }

    return 0;
}