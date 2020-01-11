class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<string> substrings;
        
        for (int i = 0; i < text.length(); i++) {
            int rem = text.length() - i;
            // cout << "i: " << i << endl;
            
            for (int j = 0; j < rem; j += 2) {
                if (j != 0) {
                    string sub = text.substr(i, j);
                    string left = sub.substr(0, j / 2);
                    string right = sub.substr(j / 2);

                    // cout << "j: " << j << ", sub: " << sub << ", left: " << left << ", right: " << right << endl;

                    bool works = true;
                    for (int k = 0; k < j / 2; k++) {
                        if (left[k] != right[k]) works = false;
                    }

                    // cout << "works: " << works;

                    if (works) substrings.emplace(sub);

                    // cout << ", num of substrings: " << substrings.size() << endl;                    
                }
            }
        }
        
        return substrings.size();
    }
};