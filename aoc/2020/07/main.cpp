#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

void partOne(string key, unordered_map<string, vector<string>> &mat, unordered_set<string> &nodes)
{
    if (mat.find(key) != mat.end())
    {
        for (string s : mat[key])
        {
            if (nodes.find(s) == nodes.end())
            {
                partOne(s, mat, nodes);
            }
        }
    }
    nodes.insert(key);
}

ull partTwo(string key, unordered_map<string, vector<pair<string, int>>> &mat)
{
    ull ans = 1;
    if (mat.find(key) != mat.end())
    {
        for (auto p : mat[key])
        {
            ull bags = (p.second) * partTwo(p.first, mat);
            ans += bags;
        }
    }
    return ans;
}

int main()
{
    ifstream fin("input.txt", ios::in);
    unordered_map<string, vector<pair<string, int>>> mat;
    string temp;

    while (!fin.eof())
    {
        getline(fin, temp);

        // get key
        size_t space = temp.find(' ');
        string key = temp.substr(0, space);
        temp = temp.substr(space + 1);
        space = temp.find(' ');
        key = key + " " + temp.substr(0, space);
        temp = temp.substr(temp.find("contain") + 8);

        if (temp != "no other bags.")
        {
            size_t comma = temp.find(',');
            while (comma != string::npos)
            {
                string val = temp.substr(0, comma);
                int amt = val[0] - '0';
                cout << val << " " << amt << endl;
                size_t bag = val.find("bag");
                val = val.substr(2, bag - 3);
                mat[key].push_back({val, amt});
                temp = temp.substr(comma + 2);
                comma = temp.find(',');
            }

            int amt = temp[0] - '0';
            size_t bag = temp.find("bag");
            temp = temp.substr(2, bag - 2);
            temp.pop_back();
            mat[key].push_back({temp, amt});
        }
    }

    for (auto it = mat.begin(); it != mat.end(); ++it)
    {
        cout << it->first << ": ";
        for (auto p : it->second)
            cout << p.second << "x " << p.first << ", ";
        cout << endl;
    }

    // unordered_set<string> nodes;
    // partOne("shiny gold", mat, nodes);
    // cout << nodes.size() - 1 << endl;

    // for (string s : nodes)
    //     cout << s << " ";
    // cout << endl;

    cout << partTwo("shiny gold", mat) - 1 << endl;

    return 0;
}