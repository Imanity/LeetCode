#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }
        char ch = strs[0][0];
        for(int i = 0; i < strs.size(); ++i) {
            if(strs[i].length() == 0 || strs[i][0] != ch) {
                return "";
            }
        }
        stringstream stream;
        stream << ch;
        vector<string> newStrs;
        for(int i = 0; i < strs.size(); ++i) {
            newStrs.push_back(strs[i].substr(1));
        }
        return (stream.str() + longestCommonPrefix(newStrs));
    }
};

int main() {
    Solution s;
    string str[] = {"Hi", "Hello", "How are you"};
    vector<string> strs(&str[0], &str[3]);
    cout << s.longestCommonPrefix(strs) << endl;
    cin.get();
    return 0;
}
