#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

unordered_map<ull, vector<string>> m;
unordered_map<ull, unordered_map<ull, pair<ull, ull>>> edges;
unordered_map<ull, vector<ull>> intersection;
vector<vector<ull>> tilegrid;
vector<string> image;

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

void flip(vector<string>& v, ull dir) {
    ull n = v.size();
    if (dir) for (int i = 0; i < n; i++)
        v[i] = reverse(v[i]);
    else for (int i = 0; i < (n/2); i++) 
        swap(v[i], v[n-1-i]);
}

// Based on https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/
void sbin(vector<string>& v) {
    ull n = v.size();
    for (int i = 0; i < (n/2); i++) {
        for (int j = i; j < n-1-i; j++) {
            char temp = v[i][j];
            v[i][j] = v[n - 1 - j][i];
            v[n - 1 - j][i] = v[n - 1 - i][n - 1 - j];
            v[n - 1 - i][n - 1 - j] = v[j][n - 1 - i];
            v[j][n - 1 - i] = temp;
        }
    }
}

void flipTile(ull tile, ull dir) {
    dir %= 2;   // 0 is top, 1 right, 2 bottom, 3 left
    flip(m[tile], dir);

    ull notdir = (dir != 1);
    swap(edges[tile][notdir].first, edges[tile][notdir].second);
    swap(edges[tile][notdir+2].first, edges[tile][notdir+2].second);
    swap(edges[tile][dir], edges[tile][dir+2]);
    swap(intersection[tile][dir], intersection[tile][dir+2]);
}

// Rotate tile clockwise by 90 degrees. 
void sbinTile(ull tile) {
    sbin(m[tile]);

    ull t0 = edges[tile][0].first, t1 = edges[tile][0].second;
    ull r0 = edges[tile][1].first, r1 = edges[tile][1].second;
    ull b0 = edges[tile][2].first, b1 = edges[tile][2].second;  
    ull l0 = edges[tile][3].first, l1 = edges[tile][3].second;
    
    edges[tile][0] = {l1, l0};
    edges[tile][1] = {t0, t1};
    edges[tile][2] = {r1, r0};
    edges[tile][3] = {b0, b1};

    ull temp = intersection[tile][3];
    for (ull i = 3; i > 0; i--) 
        intersection[tile][i] = intersection[tile][i-1];
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

void makeGrid() {
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
    while (intersection[tl][0] || intersection[tl][3]) {
        if (!intersection[tl][0] && !intersection[tl][1]) flipTile(tl, 1);
        else if (!intersection[tl][2] && !intersection[tl][1]) 
            for (int i = 0; i < 2; i++) sbinTile(tl);
        else if (!intersection[tl][2] && !intersection[tl][3]) flipTile(tl, 0);
    }

    // build top row of grid
    for (int i = 1; i < root; i++) {
        ull cur = grid[0][i-1];
        ull nxt = intersection[cur][1];
        ull dir = 0;
        bool found = false;
        while (dir < 4 && !found) {
            if (intersection[nxt][dir] == cur) found = true;
            else dir++;
        }
        for (int i = dir; i < 3; i++) sbinTile(nxt);
        if (edges[cur][1].first != edges[nxt][3].first) 
            flipTile(nxt, 0);
        grid[0][i] = nxt;
    }

    // build rest of rows from each top element
    for (int j = 0; j < root; j++) {
        for (int i = 1; i < root; i++) {
            ull cur = grid[i-1][j];
            ull nxt = intersection[cur][2];
            ull dir = 0;
            bool found = false;
            while (dir < 4 && !found) {
                if (intersection[nxt][dir] == cur) found = true;
                else dir++;
            }
            while (dir != 0) {
                sbinTile(nxt);
                dir = (dir + 1) % 4;
            }
            if (edges[cur][2].first != edges[nxt][0].first) 
                flipTile(nxt, 1);
            grid[i][j] = nxt;
        }
    }

    tilegrid = grid;
}

void makeImage() {
    if (tilegrid.size() == 0) makeGrid();
    for (int i = 0; i < tilegrid.size(); i++) for (int j = 1; j < 9; j++) {
        string s = "";
        for (int k = 0; k < tilegrid[0].size(); k++)
            s = s + m[tilegrid[i][k]][j].substr(1, 8);
        image.push_back(s);
    }
}

ull monsters(vector<string>& im) {
    vector<string> seal = {
       "                  # ",
       "#    ##    ##    ###",
       " #  #  #  #  #  #   " 
    };
    ull h = 3, w = seal[0].size(), n = im.size(), a = 0;

    for (int i = 0; i < n-h; i++) for (int j = 0; j < n-w; j++) {
        bool good = true;
        for (int i2 = 0; i2 < h && good; i2++) 
            for (int j2 = 0; j2 < w && good; j2++)
                if (seal[i2][j2] != ' ' && im[i+i2][j+j2] != '#') 
                    good = false;

        if (good) {
            a++;
            for (int i2 = 0; i2 < h; i2++) for (int j2 = 0; j2 < w; j2++)
                if (seal[i2][j2] != ' ') im[i+i2][j+j2] = 'O';
        }
    }

    return a;
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
    makeGrid();
    makeImage();
    ull is = image.size();

    vector<vector<string>> images(8, vector<string>(is, ""));
    for (int i = 0; i < 8; i++) 
        for (int j = 0; j < is; j++)
            images[i][j] = image[j];

    for (int i = 4; i < 8; i++) flip(images[i], 0);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < (i % 4); j++) 
            sbin(images[i]);
    
    ull maxVal = 0, maxIdx = 0;
    for (int i = 0; i < 8; i++) {
        ull m = monsters(images[i]);
        if (m > maxVal) {
            maxIdx = i;
            maxVal = m;
        }
    }

    ull ans = 0;
    for (int i = 0; i < is; i++) for (int j = 0; j < is; j++)
        if (images[maxIdx][i][j] == '#') ans++;
    return ans;
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

    cout << "part 1: " << part1() << endl;
    cout << "part 2: " << part2() << endl;
    return 0;
}