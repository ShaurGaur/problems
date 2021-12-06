#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

vector<ull> numbers;
vector<vector<vector<ull>>> boards;
vector<ull> scores;

void split(string s) {
    string num;

    while (s.length() > 0) {
        size_t comma = s.find(',');

        if (comma == string::npos) {
            num = s;
            s = "";
        }
        else {
            num = s.substr(0, comma);
            s = s.substr(comma + 1);
        }

        numbers.push_back(stoull(num));
    }
}

bool bingo(vector<vector<bool>>& v) {

    for (size_t i = 0; i < 5; i++) {
        if (v[i][0] && v[i][1] && v[i][2] && v[i][3] && v[i][4])
            return true;
        if (v[0][i] && v[1][i] && v[2][i] && v[3][i] && v[4][i])
            return true;
    }

    return false;
}

ull score(vector<vector<ull>>& board, vector<vector<bool>>& marked) {
    ull score = 0;
    for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++)
        if (!marked[i][j]) score += board[i][j];
    
    return score;
}

void printStuff(int x, vector<vector<vector<bool>>>& marked) {
    cout << "Number: " << x << endl << endl;

    for (int i = 0; i < boards.size(); i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (marked[i][j][k]) cout << "XXXX\t";
                else cout << boards[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << "score: " << score(boards[i], marked[i]) << endl;
        cout << endl;
    }

    cout << endl;
}

ull partOne() {
    int n = boards.size();
    vector<vector<vector<bool>>> marked(n, vector<vector<bool>>(5, vector<bool>(5, false)));
    
    for (ull x : numbers) {
        for (ull i = 0; i < boards.size(); i++)
            for (ull j = 0; j < 5; j++)
                for (ull k = 0; k < 5; k++)
                    if (boards[i][j][k] == x)
                        marked[i][j][k] = true;
        
        // printStuff(x, marked);

        for (int i = 0; i < boards.size(); i++) if (bingo(marked[i])) {
            scores.push_back(x * score(boards[i], marked[i]));
            boards.erase(boards.begin() + i);
            marked.erase(marked.begin() + i);
            i--;
        }
    }
    
    return scores[0];
}

ull partTwo() {
    return scores[scores.size() - 1];
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
    fin >> x;
    split(x);

    while (!fin.eof()) {
        vector<vector<ull>> board(5, vector<ull>(5));
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                fin >> board[i][j];
        boards.push_back(board);
    }

    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
    return 0;
}