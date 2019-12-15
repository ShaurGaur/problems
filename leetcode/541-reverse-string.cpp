class Solution {
public:
    string reverseStr(string s, int k) {
        string output = "";
        if (s.length() >= k) {
            size_t pos = 0;
            size_t len = k;
            string word = s.substr(pos, len);

            for (int i = word.length() - 1; i >= 0; i--) {
                output += word[i];
            }

            if (k < s.length() - k) {
                pos = k;
                word = s.substr(pos, min(len, s.length() - k));
                output += word;
                cout << output << endl;


                if (s.substr(pos + k).length() != 0) {
                    output += reverseStr(s.substr(pos + k), k);
                }
            }
            else {
                output += s.substr(k);
            }
        }
        else {
            for (int i = s.length() - 1; i >= 0; i--) {
                output += s[i];
            } 
        }
        return output;
    }
};