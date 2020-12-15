#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
using namespace std;

ull foo(vector<ull>& nums) {
    int n = nums.size();
    unordered_map<ull, vector<int>> says;
    for (int i = 0; i < n; i++)
        says[nums[i]].push_back(i+1);
    ull last = nums[n-1];
    
    for (int i = n+1; i <= 30000000; i++) {
        if (says[last].size() == 1) {
            last = 0;
        }
        else {
            int m = says[last].size();
            last = says[last][m-1] - says[last][m-2];
        }
        says[last].push_back(i);
        cout << i << "\r";
    }
    return last;
}

int main() {
    ifstream fin("input.txt", ios::in);
    string temp;

    while (!fin.eof()) {
        fin >> temp;
        cout << temp << ":\n";
        vector<ull> nums(0, 0);
        size_t comma = temp.find(',');
        while (comma != string::npos) {
            string n = temp.substr(0, comma);
            nums.push_back(stoul(n, nullptr, 10));
            temp = temp.substr(comma+1);
            comma = temp.find(',');
        }
        nums.push_back(stoul(temp, nullptr, 10));
        cout << foo(nums) << endl;
    }

    return 0;
}