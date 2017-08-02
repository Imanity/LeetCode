#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void get_next(string s, int *next) {
        int len = s.length(), i = 1, t = 0;
        next[1] = 0;
        while (i < len + 1) {
            while (t > 0 && s[i - 1] != s[t - 1]) {
                t = next[t];
            }
            t++;
            i++;
            if (s[i - 1] == s[t - 1]) {
                next[i] = next[t];
            } else {
                next[i] = t;
            }
        }
        while (t > 0 && s[i - 1] != s[t - 1]) {
            t = next[t];
        }
        i++;
        t++;
        next[i] = t;
    }
    int Search(string s, string t) {
        int i = 0, j = 1, n = 0, s_len = s.length(), t_len = t.length();
        int next[t_len + 2];
        get_next(t, next);
        while (t_len + 1 - j <= s_len - i) {
            if (s[i] == t[j - 1]) {
                i++;
                j++;
                if (j == t_len + 1) {
                    return (i - t_len);
                    j = next[j];
                }
            } else {
                j = next[j];
                if (j == 0) {
                    i++;
                    j++;
                }
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) {
            return -1;
        }
        return Search(haystack, needle);
    }
};

int main() {
    Solution s;
    cout << s.strStr("abcABCStringabc", "String") << endl;
    cin.get();
    return 0;
}
