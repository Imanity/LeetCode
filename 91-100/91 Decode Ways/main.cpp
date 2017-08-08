#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (!s.size()) {
            return 0;
        } else if (s.size() == 1) {
            return (s[0] != '0');
        }
        vector<int> decodings(s.size(), 0);
        decodings[0] = (s[0] != '0');
        decodings[1] = (s[0] != '0' && s[1] != '0') + isValid(s.substr(0, 2));
        for (int i = 2; i < s.size(); ++i) {
            if (isValid(s.substr(i - 1, 2))) {
                decodings[i] += decodings[i - 2];
            }
            if (s[i] != '0') {
                decodings[i] += decodings[i - 1];
            }
        }
        return decodings[s.size() - 1];
    }
    bool isValid(string s) {
        if (s[0] == '0') {
            return false;
        }
        int num = (s[0] - '0') * 10 + s[1] - '0';
        if (num <= 26) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.numDecodings("1201") << endl;
    cin.get();
    return 0;
}
