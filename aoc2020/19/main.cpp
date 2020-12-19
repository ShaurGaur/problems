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
    vector<string> messages, 
    unordered_map<ull, unordered_set<string>>& dp
) {
    ull sum = 0;
    for (string s : messages) {
        bool b = (dp[0].find(s) != dp[0].end());
        // cout << s << " " << b << endl;
        if (b) sum++;
    }

    return sum;
}

ull part2() {
    return 420;
}

int main() {
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

    // cout << "Rules:\n";
    for (auto p : rules) {
        // cout << p.first << " -> " << p.second << endl;
        dfs(rules, messages, dp, p.first);
    }

    // cout << "Messages:\n";
    // for (string s : messages) cout << "\"" << s << "\"\n";

    // cout << "DP:\n";
    // for (auto p : dp) {
    //     cout << p.first << " -> ";
    //     for (string s : p.second) cout << "'" << s << "' ";
    //     cout << endl;
    // }

    cout << "part 1: " << part1(rules, messages, dp) << endl;
    cout << "part 2: " << part2() << endl;

    return 0;
}