#include <iostream>
#include <string>
using namespace std;

/*
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ')') {
                continue;
            }
            int tmp = validParentheses(s.substr(i));
            len = tmp > len ? tmp : len;
        }
        return len;
    }
    int validParentheses(string s) {
        int len = 0, d = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                d++;
            } else {
                if(d <= 0) {
                    break;
                } else {
                    d--;
                }
            }
            if(d == 0) {
                len = i + 1;
            }
        }
        return len;
    }
};
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int l = 0, r = 0, max = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(') {
                ++l;
            } else {
                ++r;
            }
            if(l == r) {
                max = max > (2 * r) ? max : (2 * r);
            } else if (r >= l) {
                l = r = 0;
            }
        }
        l = r = 0;
        for(int i = s.length() - 1; i >= 0; --i) {
            if(s[i] == '(') {
                ++l;
            } else {
                ++r;
            }
            if(l == r) {
                max = max > (2 * r) ? max : (2 * l);
            } else if (r <= l) {
                l = r = 0;
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    cout << s.longestValidParentheses(")(())()") << endl;
    cin.get();
    return 0;
}
