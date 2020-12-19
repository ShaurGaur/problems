#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

void dfs(
    unordered_map<ull, string>& rules, 
    vector<string> messages, 
    unordered_map<ull, unordered_set<string>>& dp,
    ull r
) {
    if (!dp[r].empty()) return;
    vector<string> v;
    string s = rules[r];
    size_t bar = s.find("|");
    if (bar != string::npos) {
       v.push_back(s.substr(0, bar-1));
       v.push_back(s.substr(bar+2)); 
    }
    else v.push_back(s);

    unordered_set<string> ans;
    for (string w : v) {
        string s = w;
        unordered_set<string> a;
        a.insert("");

        while (s.length() > 0) {
            size_t space = s.find(" ");
            string n;
            if (space != string::npos) {
                n = s.substr(0, space);
                s = s.substr(space+1);
            }
            else {
                n = s;
                s = "";
            }
            ull idx = stoll(n, nullptr, 10);
            dfs(rules, messages, dp, idx);

            unordered_set<string> temp;
            for (string l : a) 
                for (string r : dp[idx])
                    temp.insert(l + r);
            a = temp;
        }
        for (string y : a) ans.insert(y);
    }
    dp[r] = ans;
}

ull part1(
    unordered_map<ull, string>& rules, 
    vector<string>& messages, 
    unordered_map<ull, unordered_set<string>>& dp
) {
    ull sum = 0;
    for (string s : messages)
        if (dp[0].find(s) != dp[0].end()) 
            sum++;
    return sum;
}

ull part2(
    unordered_map<ull, string>& rules, 
    vector<string>& messages, 
    unordered_map<ull, unordered_set<string>>& dp
) {
    ull len = dp[42].begin()->length();
    ull sum = 0;

    for (string m : messages) {
        string s = m;
        bool good = true, back = true;
        if (s.length() % len) good = false;
        unordered_map<int, int> count;
        count[42] = 0;
        count[31] = 0;
        
        while (good && s.length() > 0) {
            string cand, temp;
            if (back) {
                cand = s.substr(s.length() - len);
                temp = s.substr(0, s.length() - len);
            }
            else {
                cand = s.substr(0, len);
                temp = s.substr(len);
            }
            ull idx = (back) ? 31 : 42;
            if (dp[idx].find(cand) == dp[idx].end()) {
                if (back) {
                    back = false;
                    temp = s;
                }
                else good = false;
            }
            else count[idx]++;
            s = temp;
        }

        if (good && count[42] > count[31] && count[31] > 0)
            sum++;
    }

    return sum;
}

int main() {
    cout << "File: ";
    string temp;
    cin >> temp;
    ifstream fin(temp, ios::in);
    int ruleIn = true;
    unordered_map<ull, string> rules;
    vector<string> messages;
    unordered_map<ull, unordered_set<string>> dp;

    while (!fin.eof()) {
        getline(fin, temp);
        if (temp.size() == 1) ruleIn = false;
        else if (ruleIn) {
            size_t colon = temp.find(':');
            string s = temp.substr(0, colon);
            ull idx = stoll(s, nullptr, 10);
            temp = temp.substr(colon + 2);
            
            if (temp[0] == '"') {
                char c = temp[1];
                temp = "";
                temp.push_back(c);
                dp[idx].insert(temp);
            }
            rules[idx] = temp;
        }
        else {
            string t = "";
            for (char c : temp) 
                if (c == 'a' || c == 'b') 
                    t.push_back(c);
            messages.push_back(t);
        }
    }
    fin.close();

    dfs(rules, messages, dp, 0);
    cout << "part 1: " << part1(rules, messages, dp) << endl;
    cout << "part 2: " << part2(rules, messages, dp) << endl;

    return 0;
}