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

int main()
{
    ifstream fin("input.txt", ios::in);
    unordered_map<string, vector<string>> mat;
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
                string val = temp.substr(2, comma - 2);
                size_t bag = val.find("bag");
                val = val.substr(0, bag - 1);
                mat[val].push_back(key);
                temp = temp.substr(comma + 2);
                comma = temp.find(',');
            }

            string val = temp.substr(2);
            size_t bag = val.find("bag");
            val = val.substr(0, bag);
            val.pop_back();
            mat[val].push_back(key);
        }
    }

    // for (auto it = mat.begin(); it != mat.end(); ++it)
    // {
    //     cout << it->first << ": ";
    //     for (string s : it->second)
    //         cout << s << ", ";
    //     cout << endl;
    // }

    unordered_set<string> nodes;
    partOne("shiny gold", mat, nodes);
    cout << nodes.size() - 1 << endl;

    // for (string s : nodes)
    //     cout << s << " ";
    // cout << endl;

    return 0;
}