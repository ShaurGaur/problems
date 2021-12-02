#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

set<vector<int>> active;
set<vector<int>> active0;
int n = 0;

set<vector<int>> genDeltas(int n) {
    vector<int> zeros(n, 0);
    set<vector<int>> ans;
    
    for (int t = 0; t < n; t++) {
        set<vector<int>> temp = ans;
        ans.clear();
        if (temp.size() == 0) temp.insert({{}});
        for (vector<int> v : temp)
        for (int x = -1; x <= 1; x++) {
            vector<int> u = v;
            u.push_back(x);
            ans.insert(u);
        }
    }

    ans.erase(zeros);
    return ans;
}

void updateActive(map<vector<int>, int>& freqs) {
    set<vector<int>> active2;
    for (auto p : freqs) {
        if (p.second == 3)
            active2.insert(p.first);
        else if (p.second == 2 && active.find(p.first) != active.end())
            active2.insert(p.first);
    }
    active = active2;
}

ull solve(int d) {
    set<vector<int>> deltas = genDeltas(d);
    map<vector<int>, int> freqs;
    for (int t = 0; t < 6; t++) {
        for (vector<int> v : active) 
        for (vector<int> u : deltas) {
            vector<int> x = v;
            for (int i = 0; i < d; i++) x[i] += u[i];
            freqs[x]++;
        } 
        updateActive(freqs);
        freqs.clear();      
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
    cout << "part 1: " << solve(3) << endl;
    active = active0;
    cout << "part 2: " << solve(4) << endl;

    return 0;
}