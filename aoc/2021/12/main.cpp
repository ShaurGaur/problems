#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

unordered_map<string, unordered_set<string>> m;
unordered_set<string> small;

ull backtrack(vector<string>& path, bool onlyOne) {
    string node = path.back();
    ull ans = 0;
    if (node == "end") return 1;

    if (small.find(node) != small.end()) {
        ull visited = 0, i = 0, smalls = 0;
        while (i < path.size() - 1) {
            if (path[i] == node) visited++;
            i++;
        }
        
        if (visited && (onlyOne || node == "start")) return 0;
        else if (visited && !onlyOne) onlyOne = true;
    }

    for (string s : m[node]) {
        path.push_back(s);
        ans += backtrack(path, onlyOne);
        path.pop_back();
    }

    return ans;
}

ull partOne() {
    ull ans = 0;
    vector<string> path = {"start"};
    ans += backtrack(path, true);
    return ans;
}

ull partTwo() {
    ull ans = 0;
    vector<string> path = {"start"};
    ans += backtrack(path, false);
    return ans;
}

int main(int argc, char **argv) {
    string input_txt = "";
    if (argc < 2) {
        cout << "file: ";
        cin >> input_txt;
    }
    else input_txt = string(argv[1]);
    ifstream fin(input_txt.c_str(), ios::in);
    
    string x;
    while (!fin.eof()) {
        fin >> x;
        size_t dash = x.find('-');
        string a = x.substr(0, dash), b = x.substr(dash + 1);
        
        m[a].insert(b);
        m[b].insert(a);

        if (a[0] >= 'a' && a[0] <= 'z') small.insert(a);
        if (b[0] >= 'a' && b[0] <= 'z') small.insert(b);
    }

    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
    return 0;
}