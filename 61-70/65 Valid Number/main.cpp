#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        s = trim(s);
        if (s.size() == 0) {
            return false;
        }
        if (s.find('e') != -1) {
            int pos = s.find('e');
            if (pos == 0 || pos == s.size() - 1) {
                return false;
            }
            return isDouble(s.substr(0, pos)) && isInt(s.substr(pos + 1, s.size() - pos - 1));
        }
        return isDouble(s);
    }
    bool isInt(string s) {
        if (s.at(0) == '-' || s.at(0) == '+') {
            s = s.substr(1);
        }
        if (s.size() == 0) {
            return false;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (s.at(i) < '0' || s.at(i) > '9') {
                return false;
            }
        }
        return true;
    }
    bool isDouble(string s) {
        if (isInt(s)) {
            return true;
        }
        if (s.at(0) == '-' || s.at(0) == '+') {
            s = s.substr(1);
        }
        int pos = s.find('.');
        if (pos == -1) {
            return false;
        }
        if (s.size() == 1) {
            return false;
        }
        if (pos == 0) {
            return isInt(s.substr(pos + 1, s.size() - pos - 1)) && s.at(pos + 1) != '-' && s.at(pos + 1) != '+';
        }
        if (pos == s.size() - 1) {
            return isInt(s.substr(0, pos));
        }
        return isInt(s.substr(0, pos)) && isInt(s.substr(pos + 1, s.size() - pos - 1)) && 
            s.at(pos + 1) != '-' && s.at(pos + 1) != '+';
    }
    string trim(string s) {
        string res;
        int start = 0, end = s.size() - 1;
        while (start < s.size()) {
            if (s[start] == ' ') {
                ++start;
            } else {
                break;
            }
        }
        while (end >= 0) {
            if (s[end] == ' ') {
                --end;
            } else {
                break;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

int main() {
    Solution s;
    cout << s.isNumber("+.8") << endl;
    cin.get();
    return 0;
}
