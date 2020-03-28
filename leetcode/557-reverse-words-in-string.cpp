class Solution {
public:
    string reverseWords(string s) {
        string output = "";
        
        size_t pos = static_cast<size_t>(0);
        size_t found = s.find(" ");
        size_t len = found - pos;
        
        string word = s.substr(pos, len);
        
        for (int i = word.length() - 1; i >= 0; i--) {
            output += word[i];
        }
        
        if (found != string::npos) {
            output += " ";
            output += reverseWords(s.substr(found + 1));
        }

        return output;           
    }
};