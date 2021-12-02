#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

unordered_map<string, vector<pair<int, int>>> fields;
vector<int> myTicket;
vector<vector<int>> tickets;
vector<bool> valid(1000, false);

ull part1() {
    ull sum = 0;
    unordered_set<int> bads;
    for (int j = 0; j < tickets.size(); j++) {
        bool good = true;
        for (int i : tickets[j]) if (!valid[i]) {
            sum += i;
            good = false;
        }
        if (!good) bads.insert(j);
    } 

    vector<vector<int>> temp;
    for (int i = 0; i < tickets.size(); i++)
        if (bads.find(i) == bads.end())
            temp.push_back(tickets[i]);
    tickets = temp;

    return sum;
}

ull part2() {
    int n = tickets.size(), m = tickets[0].size();
    vector<string> fieldOrder(m);
    vector<unordered_set<string>> fieldsLeft(m);

    for (int i = 0; i < m; i++) {
        for (auto p : fields) {
            bool good = true;
            vector<int> ops = {
                p.second[0].first, p.second[0].second,
                p.second[1].first, p.second[1].second
            };
            for (int k = 0; k < n && good; k++) {
                int x = tickets[k][i];
                if ((x < ops[0] || x > ops[1]) && (x < ops[2] || x > ops[3]))
                    good = false;
            }
            if (good) fieldsLeft[i].insert(p.first);
        }
    }

    bool cleared = true;
    while (cleared) {
        cleared = false;
        for (int i = 0; i < m && !cleared; i++) {
            if (fieldsLeft[i].size() == 1) {
                string f = *(fieldsLeft[i].begin());
                fieldOrder[i] = f;
                for (int j = 0; j < m; j++)
                    fieldsLeft[j].erase(f);
                cleared = true;
            }
        }
    }

    ull prod = 1;
    for (int i = 0; i < m; i++)
        if (fieldOrder[i].find("departure") != string::npos)
            prod *= myTicket[i];
    return prod;
}

int main() {
    string temp;
    cin >> temp;
    ifstream fin(temp, ios::in);
    int section = 0;

    while (!fin.eof()) {
        getline(fin, temp);
        if (temp == "your ticket:") section == 1;
        else if (temp == "nearby tickets:") section == 2;
        else if (temp.size() == 1) section++;
        else if (section == 0) {
            size_t colon = temp.find(':');
            string field = temp.substr(0, colon);
            temp = temp.substr(colon + 2);
            size_t OR = temp.find(" or ");
            vector<string> ranges = {temp.substr(0, OR), temp.substr(OR + 4)};
            for (string r : ranges) {
                size_t dash = r.find('-');
                string s1 = r.substr(0, dash), s2 = r.substr(dash+1);
                int n1 = stoi(s1), n2 = stoi(s2);
                fields[field].push_back({n1, n2});
                for (int i = n1; i <= n2; i++) valid[i] = true;
            }
        }
        else if (section == 1 && temp[0] >= '0' && temp[0] <= '9') {
            size_t comma = temp.find(',');
            while (comma != string::npos) {
                string n = temp.substr(0, comma);
                myTicket.push_back(stoul(n, nullptr, 10));
                temp = temp.substr(comma+1);
                comma = temp.find(',');
            }
            myTicket.push_back(stoul(temp, nullptr, 10));
        }
        else if (section == 2 && temp[0] >= '0' && temp[0] <= '9') {
            tickets.push_back({});
            size_t comma = temp.find(',');
            while (comma != string::npos) {
                string n = temp.substr(0, comma);
                tickets.back().push_back(stoul(n, nullptr, 10));
                temp = temp.substr(comma+1);
                comma = temp.find(',');
            }
            tickets.back().push_back(stoul(temp, nullptr, 10));
        }
    }

    cout << "part 1: " << part1() << endl;
    cout << "part 2: " << part2() << endl;    

    return 0;
}