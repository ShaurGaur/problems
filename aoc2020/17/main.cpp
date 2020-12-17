#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

set<vector<int>> active;
set<vector<int>> active0;
int n = 0;

ull part1() {
   for (int t = 0; t < 6; t++) {
        set<vector<int>> active2;
        map<vector<int>, int> freqs;
        
        for (vector<int> v : active) {
            int j = 0;
            for (int x = (v[0] - 1); x <= (v[0] + 1); x++)
            for (int y = (v[1] - 1); y <= (v[1] + 1); y++)
            for (int z = (v[2] - 1); z <= (v[2] + 1); z++)
            if (x != v[0] || y != v[1] || z != v[2])
                freqs[{x, y, z, 0}]++;
        }

        for (auto p : freqs) {
            if (p.second == 3)
                active2.insert(p.first);
            else if (p.second == 2 && active.find(p.first) != active.end())
                active2.insert(p.first);
        }
        
        active = active2;
    }

    return active.size(); 
}

ull part2() {
   for (int t = 0; t < 6; t++) {
        set<vector<int>> active2;
        map<vector<int>, int> freqs;

        for (vector<int> v : active) {
            for (int x = (v[0] - 1); x <= (v[0] + 1); x++)
            for (int y = (v[1] - 1); y <= (v[1] + 1); y++)
            for (int z = (v[2] - 1); z <= (v[2] + 1); z++)
            for (int w = (v[3] - 1); w <= (v[3] + 1); w++)
            if (x != v[0] || y != v[1] || z != v[2] || w != v[3])
                freqs[{x, y, z, w}]++;
        }

        for (auto p : freqs) {
            if (p.second == 3)
                active2.insert(p.first);
            else if (p.second == 2 && active.find(p.first) != active.end())
                active2.insert(p.first);
        }

        active = active2;
    }

    return active.size(); 
}

int main() {
    string temp;
    cin >> temp;
    ifstream fin(temp, ios::in);
    int i = 0;

    while (!fin.eof()) {
        fin >> temp;
        n = temp.length();
        for (int j = 0; j < n; j++)
            if (temp[j] == '#')
                active.insert({i, j, 0, 0});
        i++;
    }
    fin.close();

    active0 = active;
    cout << "part 1: " << part1() << endl;
    active = active0;
    cout << "part 2: " << part2() << endl;

    return 0;
}