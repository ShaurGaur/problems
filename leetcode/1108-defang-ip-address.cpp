using namespace std;
class Solution {
public:
    string defangIPaddr(string address) {
        string output = "";
        size_t pos = static_cast<size_t>(0);
        size_t found = address.find(".");
        
        size_t len = found - pos;
        output += address.substr(pos, len);
        
        if (found != string::npos) {
            output += "[.]";
            output += defangIPaddr(address.substr(found + 1));
        }
        
        return output;
    }
};