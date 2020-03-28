class Solution {
public:
    map<int, int> solutions = {{0, 0}, {1, 1}, {2, 1}};
    int tribonacci(int n) {
        if (solutions.find(n) != solutions.end()) return solutions[n];
        else {
            int trib = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
            solutions.emplace(n, trib);
            return trib;
        }
    }
};