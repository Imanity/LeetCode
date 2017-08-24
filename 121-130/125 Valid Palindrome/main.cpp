#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for (int i = 0; i < s.size(); ++i) {
            if (isAlphanumeric(s[i])) {
                t.push_back(toLowerCase(s[i]));
            }
        }
        int n = t.size();
        for (int i = 0; i < n / 2; ++i) {
            if (t[i] != t[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
    bool isAlphanumeric(char c) {
        if (c >= 'A' && c <= 'Z') {
            return true;
        }
        if (c >= 'a' && c <= 'z') {
            return true;
        }
        if (c >= '0' && c <= '9') {
            return true;
        }
        return false;
    }
    char toLowerCase(char c) {
        if (c >= 'A' && c <= 'Z') {
            return (c - 'A' + 'a');
        }
        return c;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cin.get();
    return 0;
}
