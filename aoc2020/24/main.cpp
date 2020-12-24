#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

set<pair<int, int>> black;
vector<string> dirs;
unordered_map<string, pair<int, int>> m;

pair<int, int> decode(string s) {
    int idx = 0, x = 0, y = 0;
    string buf = "";
    while (idx < s.length()) {
        while (buf.back() != 'w' && buf.back() != 'e') {
            buf.push_back(s[idx]);
            idx++;
        }
        x += m[buf].first;
        y += m[buf].second;
        buf = "";
    }
    return {x, y};
}

int part1() {
    for (string s : dirs) {
        pair<int, int> p = decode(s);
        if (black.find(p) != black.end()) black.erase(p);
        else black.insert(p);
    }
    return black.size();
}

ull part2() {
    for (int i = 0; i < 100; i++) {
        map<pair<int, int>, ull> refs;
        for (pair<int, int> p : black) refs[p] = 0;

        for (pair<int, int> p : black) for (auto q : m)
            refs[{
                p.first + q.second.first, 
                p.second + q.second.second
            }]++;

        for (auto p : refs)
            if (black.find(p.first) != black.end() 
                && (p.second == 0 || p.second > 2))
                    black.erase(p.first);
            else if (p.second == 2) black.insert(p.first);
    }
    return black.size();
}

int main() {
    cout << "File: ";
    string temp;
    cin >> temp;
    
    ifstream fin(temp, ios::in);
    while (!fin.eof()) {
        fin >> temp;
        dirs.push_back(temp);
    }
    fin.close();

    m["e"] = {2, 0};
    m["w"] = {-2, 0};
    m["se"] = {1, -1};
    m["sw"] = {-1, -1};  
    m["ne"] = {1, 1};
    m["nw"] = {-1, 1};    

    cout << "part 1: " << part1() << endl;
    cout << "part 2: " << part2() << endl;
    return 0;
}