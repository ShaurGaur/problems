#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

unordered_map<ull, vector<string>> m;
unordered_map<ull, unordered_map<ull, pair<ull, ull>>> edges;
unordered_map<ull, vector<ull>> intersection;

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

void flip(ull tile, ull dir) {
    dir %= 2;   // 0 is top, 1 right, 2 bottom, 3 left
    if (dir) for (int i = 0; i < 10; i++)
        m[tile][i] = reverse(m[tile][i]);
    else for (int i = 0; i < 5; i++) 
        swap(m[tile][i], m[tile][9-i]);
    
    ull notdir = (dir != 1);
    swap(edges[tile][notdir].first, edges[tile][notdir].second);
    swap(edges[tile][notdir+2].first, edges[tile][notdir+2].second);
    swap(edges[tile][dir], edges[tile][dir+2]);
    swap(intersection[tile][dir], intersection[tile][dir+2]);
}

// Rotate tile clockwise by 90 degrees. 
// Based on https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/
void sbin(ull tile) {
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 9-i; j++) {
            char temp = m[tile][i][j];
            m[tile][i][j] = m[tile][9 - j][i];
            m[tile][9 - j][i] = m[tile][9 - i][9 - j];
            m[tile][9 - i][9 - j] = m[tile][j][9 - i];
            m[tile][j][9 - i] = temp;
        }
    }

    ull t0 = edges[tile][0].first, t1 = edges[tile][0].second;
    ull r0 = edges[tile][1].first, r1 = edges[tile][1].second;
    ull b0 = edges[tile][2].first, b1 = edges[tile][2].second;  
    ull l0 = edges[tile][3].first, l1 = edges[tile][3].second;
    
    edges[tile][0] = {l1, l0};
    edges[tile][1] = {t0, t1};
    edges[tile][2] = {r1, r0};
    edges[tile][3] = {b0, b1};

    ull temp = intersection[tile][3];
    for (ull i = 0; i < 3; i++) 
        intersection[tile][i + 1] = intersection[tile][i];
    intersection[tile][0] = temp;
}

void getEdges() {
    for (auto p : m) {
        ull idx = p.first;
        vector<string> v = p.second;
        vector<string> e = {v[0], "", v[9], ""};
        for (int i = 0; i < v.size(); i++) {
            e[1].push_back(v[i][9]);
            e[3].push_back(v[i][0]);
        }
        for (int i = 0; i < 4; i++) {
            string edge = e[i];
            ull a = str2Bit(edge), b = str2Bit(reverse(edge));
            edges[idx][i] = {a, b};
        }
    }
}

ull part1() {
    for (auto p : edges) intersection[p.first].resize(4);

    for (auto p : edges) {
        ull idxI = p.first;
        auto los_edge = p.second;

        for (auto q : los_edge) {
            ull edgeI = q.first;
            auto l2r = q.second;
            pair<ull, ull> r2l = {l2r.second, l2r.first};
            
            for (auto r : edges) if (idxI != r.first) {
                ull idxJ = r.first, edgeJ = 0;
                bool found = false;
                while (edgeJ < 4 && !found) {
                    if (edges[idxJ][edgeJ] == l2r || edges[idxJ][edgeJ] == r2l)
                        found = true;
                    else edgeJ++;
                }
                if (found) {
                    intersection[idxI][edgeI] = idxJ;
                    intersection[idxJ][edgeJ] = idxI;
                }
            }
        }
    }

    ull prod = 1;
    for (auto p : intersection) {
        ull count = 0;
        for (ull i : p.second) if (i != 0) count++;
        if (count == 2) prod *= p.first;
    }
    return prod;
}

ull part2() {
    ull tileCount = m.size();
    ull root = (ull) sqrt((double) tileCount);
    vector<vector<ull>> grid(root, vector<ull>(root, 0));

    // find top left corner
    for (auto it = intersection.begin(); it != intersection.end() && !grid[0][0]; ++it) {
        ull count = 0;
        for (ull i : it->second) if (i != 0) count++;
        if (count == 2) grid[0][0] = it->first;
    }
  
    // rotate topLeft
    ull tl = grid[0][0];
    while (intersection[tl][0] && intersection[tl][3]) {
        if (!intersection[tl][0] && !intersection[tl][1]) flip(tl, 1);
        else if (!intersection[tl][2] && !intersection[tl][1]) 
            for (int i = 0; i < 2; i++) sbin(tl);
        else if (!intersection[tl][2] && !intersection[tl][3]) flip(tl, 0);
    }

    // build rest of grid

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
    getEdges();

    // for (auto p : m) {
    //     cout << "TILE " << p.first << endl;
    //     for (string s : p.second) 
    //         cout << s << endl;
    //     cout << endl;
    // }

    // cout << "EDGES:\n";
    // for (auto p : edges) {
    //     cout << p.first << ": ";
    //     for (auto q : p.second) 
    //         cout << q.first << " { " << q.second.first << " , " << q.second.second << " } ";
    //     cout << endl;
    // }

    cout << "part 1: " << part1() << endl;
    cout << "INTER:\n";
    for (auto p : intersection) {
        cout << p.first << ": ";
        for (int i = 0; i < 4; i++) 
            cout << i << ":" << p.second[i] << "\t";
        cout << endl;
    }
    cout << "part 2: " << part2() << endl;

    return 0;
}