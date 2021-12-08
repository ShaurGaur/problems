#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

vector<vector<string>> patterns;
vector<vector<string>> outputs;
ull n;

ull partOne() {
    ull ans = 0;

    for (ull i = 0; i < n; i++) {
        for (ull j = 0; j < 4; j++) {
            switch (outputs[i][j].length()) {
                case 2:
                    ans++;
                    break;
                case 4:
                    ans++;
                    break;
                case 3:
                    ans++; 
                    break;
                case 7:
                    ans++;
                    break;
            }
        }
    }

    return ans;
}

bool lenSort(string a, string b) {
    return a.length() < b.length();
}

ull intersections(string a, string b) {
    vector<int> letterdata(26, 0);
    for (char c : a) letterdata[c - 'a']++;
    for (char c : b) letterdata[c - 'a']++;

    ull ans = 0;
    for (int i : letterdata) if (i == 2) ans++;
    return ans;    
}

ull getNum(vector<string>& p, vector<string>& q) {
    ull ans = 0;
    sort(p.begin(), p.end(), lenSort);

    vector<string> keys(10, "");
    keys[8] = p.back();
    keys[1] = p[0];
    keys[7] = p[1];
    keys[4] = p[2];

    vector<string> fives(p.begin() + 3, p.begin() + 6);
    vector<string> sixes(p.begin() + 6, p.begin() + 9);    

    vector<int> fives_int7(3, 0);
    vector<int> fives_int4(3, 0);
    vector<int> sixes_int7(3, 0);
    vector<int> sixes_int4(3, 0);
    
    for (int i = 0; i < 3; i++) {
        fives_int7[i] = intersections(fives[i], keys[7]);
        fives_int4[i] = intersections(fives[i], keys[4]);
        sixes_int7[i] = intersections(sixes[i], keys[7]);
        sixes_int4[i] = intersections(sixes[i], keys[4]);
    }

    for (int i = 0; i < 3; i++) {
        if (fives_int7[i] == 3) keys[3] = fives[i];
        else if (fives_int4[i] == 3) keys[5] = fives[i];
        else keys[2] = fives[i];

        if (sixes_int7[i] == 2) keys[6] = sixes[i];
        else if (sixes_int4[i] == 4) keys[9] = sixes[i];
        else keys[0] = sixes[i];
    }

    for (string s : q) {
        bool ansFound = false;
        for (int i = 0; i < 10 && !ansFound; i++) {
            if (intersections(keys[i], s) == max(s.length(), keys[i].length())) {
                ansFound = true;
                ans = (ans * 10) + i;
            }
        }
    }
    
    return ans;
}

ull partTwo() {
    ull ans = 0;
    for (int i = 0; i < n; i++)
        ans += getNum(patterns[i], outputs[i]);
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
        patterns.push_back({});
        for (int i = 0; i < 10; i++) {
            fin >> x;
            patterns.back().push_back(x);
        }

        fin >> x;

        outputs.push_back({});
        for (int i = 0; i < 4; i++) {
            fin >> x;
            outputs.back().push_back(x);
        }
    }

    n = patterns.size();

    cout << "Part 1: " << partOne() << endl;
    cout << "Part 2: " << partTwo() << endl;
    return 0;
}