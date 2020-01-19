#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Clear duplicated spacing
        bool isSpacing = false;
        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (isSpacing) {
                    s.erase(s.begin() + i--);
                } else {
                    isSpacing = true;
                }
            } else {
                isSpacing = false;
            }
        }
        if (s[0] == ' ') {
            s.erase(s.begin());
        }
        if (s[s.size() - 1] == ' ') {
            s.erase(s.end() - 1);
        }

        // Reverse s
        reverse(s.begin(), s.end());

        // Reverse each word
        string::iterator a = s.begin(), b = a;
        while (b != s.end()) {
            if (*b == ' ') {
                reverse(a, b);
                a = ++b;
            } else {
                ++b;
            }
        }
        reverse(a, b);
        return s;
    }
    inline void reverse(string::iterator head, string::iterator tail) {
        while (head < tail) {
            swap(*head++, *--tail);
        }
    }
};

int main() {
    Solution s;
    cout << s.reverseWords("a good   example") << "." << endl;
}
