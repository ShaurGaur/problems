#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

unordered_map<ull, vector<string>> m;
unordered_map<ull, set<pair<int, int>>> edges;

ull str2Bit(string s) {
    ull x = 0;
    for (char c : s) {
        x <<= 1;
        x += (c == '#') ? 1 : 0;
    }
    return x;
}

string reverse(string s) {
    string t;
    for (int i = s.length() - 1; i >= 0; i--)
        t.push_back(s[i]);
    return t;
}

void getEdges() {
    for (auto p : m) {
        ull idx = p.first;
        vector<string> v = p.second;
        vector<string> e = {v[0], v[9], "", ""};
        for (int i = 0; i < v.size(); i++) {
            e[2].push_back(v[i][0]);
            e[3].push_back(v[i][9]);
        }
        for (string edge : e) {
            ull a = str2Bit(edge), b = str2Bit(reverse(edge));
            edges[idx].insert({a, b});
        }
    }
}

ull part1() {
    auto map = edges;
    for (auto p : map) {
        ull idx = p.first;
        for (auto q : p.second) {
            pair<int, int> nq = {q.second, q.first};
            bool unique = true;
            for (auto& r : map) if (r.first != p.first) {
                if (map[r.first].find(q) != map[r.first].end()) {
                    unique = false;
                    map[r.first].erase(q);
                }
                if (map[r.first].find(nq) != map[r.first].end()) {
                    unique = false;
                    map[r.first].erase(nq);
                }
            }
            if (!unique) map[p.first].erase(q);
        }
    }

    ull prod = 1;
    for (auto p : map)
        if (p.second.size() == 2)
            prod *= p.first;

    cout << "AFTER:\n";
    for (auto p : map) {
        cout << p.first << ": ";
        for (auto q : p.second) 
            cout << "{ " << q.first << " , " << q.second << " } ";
        cout << endl;
    }

    // cout << "AFTER:\n";
    // for (auto p : edges) {
    //     cout << p.first << ": ";
    //     for (auto q : p.second) 
    //         cout << "{ " << q.first << " , " << q.second << " } ";
    //     cout << endl;
    // }

    return prod;
}

ull part2() {
    return 420;
}

int main() {
    string temp;
    cin >> temp;
    ifstream fin(temp, ios::in);
    ull cur = 0;

    while (!fin.eof()) {
        fin >> temp;
        if (temp[0] >= '0' && temp[0] <= '9') {
            temp.pop_back();
            cur = stoll(temp, nullptr, 10);
        }
        else if (temp[0] == '#' || temp[0] == '.')
            m[cur].push_back(temp);
    }
    fin.close();

    // for (auto p : m) {
    //     cout << "TILE " << p.first << endl;
    //     for (string s : p.second) 
    //         cout << s << endl;
    //     cout << endl;
    // }
    getEdges();

    cout << "BEFORE:\n";
    for (auto p : edges) {
        cout << p.first << ": ";
        for (auto q : p.second) 
            cout << "{ " << q.first << " , " << q.second << " } ";
        cout << endl;
    }
    ull x = part1();

    cout << "part 1: " << x << endl;
    cout << "part 2: " << part2() << endl;

    return 0;
}