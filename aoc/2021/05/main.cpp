#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

vector<ull> orig_x, orig_y, dest_x, dest_y;

void split(string s) {
    ull idx, val;
    
    idx = s.find(',');
    val = stoull(s.substr(0, idx));
    s = s.substr(idx + 1);
    orig_x.push_back(val);

    idx = s.find(' ');
    val = stoull(s.substr(0, idx));
    s = s.substr(idx + 4);
    orig_y.push_back(val);

    idx = s.find(',');
    val = stoull(s.substr(0, idx));
    s = s.substr(idx + 1);
    dest_x.push_back(val);

    val = stoull(s);
    dest_y.push_back(val);
}

ull partOne() {
    ull n = 1000, ans = 0;
    vector<vector<ull>> board(n, vector<ull>(n, 0));

    for (int i = 0; i < orig_x.size(); i++) {
        ull min_x = min(orig_x[i], dest_x[i]);
        ull max_x = max(orig_x[i], dest_x[i]);
        ull min_y = min(orig_y[i], dest_y[i]);
        ull max_y = max(orig_y[i], dest_y[i]);

        if (max_y == min_y) {
            for (int j = min_x; j <= max_x; ++j) {
                board[j][min_y]++;
                if (board[j][min_y] == 2) ans++;
            }
        }

        else if (max_x == min_x) {
            for (int j = min_y; j <= max_y; ++j) {
                board[min_x][j]++;
                if (board[min_x][j] == 2) ans++;
            }
        }
    }

    return ans;
}

ull partTwo() {
    ull n = 1000, ans = 0;
    vector<vector<ull>> board(n, vector<ull>(n, 0));
    cout << endl;

    for (int i = 0; i < orig_x.size(); i++) {
        ull min_x = min(orig_x[i], dest_x[i]);
        ull max_x = max(orig_x[i], dest_x[i]);
        ull min_y = min(orig_y[i], dest_y[i]);
        ull max_y = max(orig_y[i], dest_y[i]);

        // printf("(%u,%u) to (%u,%u)\n", min_x, min_y, max_x, max_y);

        if (max_y == min_y) {
            for (int j = min_x; j <= max_x; ++j) {
                board[j][min_y]++;
                if (board[j][min_y] == 2) ans++;
            }
        }

        else if (max_x == min_x) {
            for (int j = min_y; j <= max_y; ++j) {
                board[min_x][j]++;
                if (board[min_x][j] == 2) ans++;
            }
        }

        else {
            ull delta = max_x - min_x;
            for (int j = 0; j <= delta; ++j) {
                ull x_factor = (orig_x[i] < dest_x[i]) ? 1 : -1;
                ull y_factor = (orig_y[i] < dest_y[i]) ? 1 : -1;
                ull x_pos = orig_x[i] + (x_factor * j);
                ull y_pos = orig_y[i] + (y_factor * j);
                board[x_pos][y_pos]++;
                if (board[x_pos][y_pos] == 2) ans++;
            }
        }

        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         if (board[i][j])
        //             cout << board[i][j];
        //         else cout << '-';
        //     }
        //     cout << endl;
        // }
        // cout << endl;

    }



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
        getline(fin, x);
        split(x);
    }

    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
    return 0;
}