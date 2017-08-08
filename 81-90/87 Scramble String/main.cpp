#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        if (s1 == s2) {
            return true;
        }
        int table[26] = { 0 };
        for (int i = 0; i < s1.size(); ++i) {
            table[s1[i] - 'a']++;
            table[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (table[i]) {
                return false;
            }
        }
        for (int i = 1; i <= s1.size() - 1; ++i) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))) {
                return true;
            }
            if ((isScramble(s1.substr(0, i), s2.substr(s2.size() - i)) && isScramble(s1.substr(i), s2.substr(0, s2.size() - i)))) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isScramble("great", "rgtae") << endl;
    cin.get();
}