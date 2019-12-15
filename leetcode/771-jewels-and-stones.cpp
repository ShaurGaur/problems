class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        for (int s = 0; s < S.length(); s++) {
            for (int j = 0; j < J.length(); j++) {
                if (S[s] == J[j])
                    count++;
            }
        }
        return count;
    }
};