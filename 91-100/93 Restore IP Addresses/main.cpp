#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        return getIp(s, 1);
    }
    vector<string> getIp(string s, int pos) {
        vector<string> ip;
        if (pos == 4) {
            if (isValid(s)) {
                ip.push_back(s);
            }
            return ip;
        }
        int n = s.size();
        string curr;
        for (int i = 1; i <= 3; ++i) {
            if (isValid(s.substr(0, i)) && (n - i) >= (4 - pos) && (n - i) <= 3 * (4 - pos)) {
                vector<string> tmp = getIp(s.substr(i), pos + 1);
                for (int j = 0; j < tmp.size(); ++j) {
                    curr = s.substr(0, i) + "." + tmp[j];
                    ip.push_back(curr);
                }
            }
        }
        return ip;
    }
    int strToInt(string str) {
        int num = 0;
        for (int i = 0; i < str.size(); ++i) {
            num = num * 10 + (str[i] - '0');
        }
        return num;
    }
    bool isValid(string str) {
        if (str.size() > 1 && str[0] == '0') {
            return false;
        }
        if (str.size() < 3) {
            return true;
        }
        if (strToInt(str) <= 255) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<string> ip = s.restoreIpAddresses("25525511135");
    for (int i = 0; i < ip.size(); ++i) {
        cout << ip[i] << endl;
    }
    cin.get();
    return 0;
}
