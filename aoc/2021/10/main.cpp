#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

vector<string> v;
vector<stack<char>> stacks;

ull partOne() {
    ull ans = 0;
    
    unordered_map<char, ull> m;
    m[')'] = 3;
    m[']'] = 57;
    m['}'] = 1197;
    m['>'] = 25137;

    for (int i = 0; i < v.size(); i++) {
        string s = v[i];
        stack<char> x;
        bool unfound = true;
        
        for (int j = 0; j < s.length(); j++) {
            char c = s[j];
            if (c == '{' || c == '(' || c == '[' || c == '<') {
                x.push(c);
            }
            else {
                bool good = false;
                char d = x.top();
                if (d == '(' && c == ')') good = true;
                if (d == '{' && c == '}') good = true;
                if (d == '[' && c == ']') good = true;
                if (d == '<' && c == '>') good = true;
                
                if (good) {x.pop();}
                else if (unfound) {
                    ans += m[c];
                    // cout << "Fail on string " << i;
                    // cout << " char " << j << ": " << c;
                    // cout << " stacktop: " << d;
                    // cout << " adding " << m[c] << endl;
                    unfound = false;
                }
            }
        }

        if (unfound && !x.empty()) {
            stacks.push_back(x);
        }
    }

    return ans;
}

ull partTwo() {
    ull ans = 0;
    vector<ull> scores;

    unordered_map<char, ull> m;
    m['('] = 1;
    m['['] = 2;
    m['{'] = 3;
    m['<'] = 4;

    for (stack<char> s : stacks) {
        ull score = 0;
        
        while (!s.empty()) {
            score *= 5;
            score += m[s.top()];
            s.pop();
        }

        scores.push_back(score);
    }

    sort(scores.begin(), scores.end());
    ans = scores[scores.size() / 2];
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
        v.push_back(x);
    }

    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
    return 0;
}