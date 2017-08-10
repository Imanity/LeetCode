#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }
        bool table[s1.size() + 1][s2.size() + 1];
        for (int i = 0; i <= s1.size(); ++i) {
            for (int j = 0; j <= s2.size(); ++j) {
                if (!i && !j) {
                    table[i][j] = true;
                } else if (!i) {
                    table[i][j] = s3[j - 1] == s2[j - 1] && table[i][j - 1];
                } else if (!j) {
                    table[i][j] = s3[i - 1] == s1[i - 1] && table[i - 1][j];
                } else {
                    table[i][j] = (s3[i + j - 1] == s1[i - 1] && table[i - 1][j]) || 
                        (s3[i + j - 1] == s2[j - 1] && table[i][j - 1]);
                }
            }
        }
        return table[s1.size()][s2.size()];
    }
};

int main() {
    Solution s;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cin.get();
    return 0;
}
