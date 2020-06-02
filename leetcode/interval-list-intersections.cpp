#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
    void check(vector<vector<int>>& ans, vector<int>& a, vector<int>& b, int l, int r) {
        bool valid = (a[0] <= l) && (l <= a[1]) && (a[0] <= r) && (r <= a[1])
                  && (b[0] <= l) && (l <= b[1]) && (b[0] <= r) && (r <= b[1]);
        
        printf("\n\nl: %d, r: %d, a: [%d, %d], b: [%d, %d], valid: %d\n",
               l, r, a[0], a[1], b[0], b[1], valid);
        
        if (valid) {
            if (!ans.empty()) printf("back: [%d, %d]\n", ans.back()[0], ans.back()[1]);
            if (!ans.empty() && (ans.back().at(1) >= l)) ans.back().at(1) = r;
            else ans.push_back({l, r});
        }
    }
    
    void wrapCheck(vector<vector<int>>& A, 
                   vector<vector<int>>& B, 
                   vector<vector<int>>& ans, 
                   int& iA, int& iB, int l, int r) {
        
            if (iA >= A.size() || iB >= B.size()) return;
            
            if (r > A[iA][1]) iA++;
            if (r > B[iB][1]) iB++;
            
            if (iA >= A.size() || iB >= B.size()) return;
            check(ans, A[iA], B[iB], l, r);
    }
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        set<int> cset;
        for (vector<int> a : A) for (int i : a) cset.emplace(i);
        for (vector<int> b : B) for (int i : b) cset.emplace(i);
        
        vector<int> cvec(cset.begin(), cset.end());
        for (int i : cvec) cout << i << " ";
        cout << endl;
        
        vector<vector<int>> ans;
        
        int iA = 0, iB = 0, i = 0;
        while (i < cvec.size()) {
            wrapCheck(A, B, ans, iA, iB, cvec[i], cvec[i]);
            if (i + 1 < cvec.size()) wrapCheck(A, B, ans, iA, iB, cvec[i], cvec[i+1]);
            i++;
            
            // for (vector<int> a : ans) printf("[%d, %d] ", a[0], a[1]);
            // cout << endl;
        }
        
        return ans;
    }
// };

int main() {
    vector<vector<int>> A = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> B = {{1,5},{8,12},{15,24},{25,26}};

    vector<vector<int>> ans = intervalIntersection(A, B);

    for (vector<int> a : ans) printf("[%d, %d] ", a[0], a[1]);
    cout << endl;
}