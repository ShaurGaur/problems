#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

void printSet(unordered_set<string> &s)
{
    for (auto it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    ifstream fin("input.txt", ios::in);
    string temp;
    unordered_set<string> keys({"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"});
    unordered_set<string> toFind = keys;
    int valid = 0;

    while (!fin.eof())
    {
        getline(fin, temp);
        if (temp == "")
        {
            if (toFind.size() == 0)
                valid++;
            toFind = keys;
        }
        else
        {
            size_t colon = temp.find(':');
            while (colon != string::npos)
            {
                string key = temp.substr(colon - 3, 3);
                size_t space = temp.find(' ');
                if (space == string::npos)
                    space = temp.length();
                cout << colon << " " << space << " " << temp.length() << endl;
                string value = temp.substr(colon + 1, space - colon - 1);
                bool good = false;
                long v = strtol(value.c_str(), nullptr, 10);
                cout
                    << "'\tkey: '" << key
                    << "'\tval: '" << value
                    << "'\t\tv: " << v;

                if (key == "byr")
                {
                    if (v >= 1920 && v <= 2002)
                        good = true;
                }
                else if (key == "iyr")
                {
                    if (v >= 2010 && v <= 2020)
                        good = true;
                }
                else if (key == "eyr")
                {
                    if (v >= 2020 && v <= 2030)
                        good = true;
                }
                else if (key == "hgt")
                {
                    string unit = "aa";
                    unit[1] = value.back();
                    value.pop_back();
                    unit[0] = value.back();
                    value.pop_back();

                    if (unit == "cm" && v >= 150 && v <= 193)
                        good = true;
                    if (unit == "in" && v >= 59 && v <= 76)
                        good = true;
                }
                else if (key == "hcl")
                {
                    if (value.length() == 7 && value[0] == '#')
                    {
                        bool bad = false;
                        for (int i = 1; i < 7 && !bad; i++)
                            if (value[i] < '0' && value[i] > '9' && value[i] < 'a' && value[i] > 'f')
                                bad = true;
                        if (!bad)
                            good = true;
                    }
                }
                else if (key == "ecl")
                {
                    unordered_set<string> colors({"amb", "blu", "gry", "grn", "hzl", "oth", "brn"});
                    if (colors.find(value) != colors.end())
                        good = true;
                }
                else if (key == "pid")
                {
                    if (value.length() == 9)
                    {
                        bool bad = false;
                        for (char c : value)
                            if (c < '0' && c > '9')
                                bad = true;
                        if (!bad)
                            good = true;
                    }
                }

                cout << "\t\tgood: " << good << endl;

                if (good)
                    toFind.erase(key);
                if (space != temp.length())
                    temp = temp.substr(space + 1);
                else
                    temp = "";
                colon = temp.find(':');
            }
        }
    }

    cout << valid << endl;

    return 0;
}