#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

unordered_map<string, ull> key;
unordered_map<string, set<string>> cands;
map<string, string> danger;

ull part1() {
    set<string> bads;
    bool cleared = true;
    while (cleared) {
        cleared = false;
        for (auto p : cands) if (p.second.size() == 1) {
            string s = *(p.second.begin());
            bads.insert(s);
            danger[p.first] = s;
            cleared = true;
            for (auto q : cands) cands[q.first].erase(s);
        }
    }

    ull sum = 0;
    for (auto p : key)
        if (bads.find(p.first) == bads.end())
            sum += p.second;
    return sum;
}

string part2() {
    string ans = "";
    for (auto p : danger)
        ans = ans + p.second + ","; 
    ans.pop_back();
    return ans;
}

int main() {
    string temp, word;
    cin >> temp;
    ifstream fin(temp, ios::in);

    while (!fin.eof()) {
        set<string> ingredients;
        set<string> allergens;
        getline(fin, temp);
        int mode = 1;
        
        size_t space = temp.find(' ');
        while (space != string::npos) {
            word = temp.substr(0, space);
            temp = temp.substr(space+1);
            if (word[0] == '(') mode = 2;
            else if (mode == 1) {
                ingredients.insert(word);
                key[word]++;
            }
            else if (mode == 2) {
                while (word.back() < 'a' || word.back() > 'z')
                    word.pop_back();
                allergens.insert(word);
            }
            space = temp.find(' ');
        }
        while (temp.back() < 'a' || temp.back() > 'z')
            temp.pop_back();
        allergens.insert(temp);

        for (string a : allergens) {
            if (cands[a].size() == 0) 
                cands[a].insert(ingredients.begin(), ingredients.end());
            else {
                vector<string> v(cands[a].size() + ingredients.size(), "");
                auto it = set_intersection(
                    cands[a].begin(), cands[a].end(),
                    ingredients.begin(), ingredients.end(), 
                    v.begin()
                );
                v.resize(it-v.begin());
                set<string> r(v.begin(), v.end());
                cands[a] = r;
            }
        }
    }
    fin.close();

    cout << "part 1: " << part1() << endl;
    cout << "part 2: " << part2() << endl;

    return 0;
}