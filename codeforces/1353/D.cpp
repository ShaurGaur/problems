#include <bits/stdc++.h> 
using namespace std;

bool heapComp(pair<int, int> a, pair<int, int> b) {
    int a_dist = a.second - a.first;
    int b_dist = b.second - b.first;

    if (a_dist < b_dist) return true;
    if (a_dist > b_dist) return false;
    return a.first > b.first;
}

int* solve(int n) {
    int* a = new int[n];
    memset(a, 0, n*sizeof(int));
    
    vector<pair<int,int>> ranges = {{0, n-1}};
    make_heap(ranges.begin(), ranges.end(), heapComp);

    for (int i = 1; i <= n; i++) {
        pair<int, int> p = ranges.front();
        pop_heap(ranges.begin(), ranges.end(), heapComp);
        ranges.pop_back();
        
        int sum = p.second - p.first + 1;
        int index = (sum % 2 == 1) ? (p.first + p.second) / 2 : (p.first + p.second - 1) / 2;
        a[index] = i;

        if (index - 1 >= p.first) {
            ranges.push_back({p.first, index-1});
            push_heap(ranges.begin(), ranges.end(), heapComp);
        }
        if (index + 1 <= p.second) {
            ranges.push_back({index + 1, p.second});
            push_heap(ranges.begin(), ranges.end(), heapComp);
        }
    }

    return a;
}

int main() {
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        int* a = solve(n);
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
        delete [] a;
    }
}