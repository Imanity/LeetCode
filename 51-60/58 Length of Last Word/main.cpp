#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool isWord = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s.at(i) == ' ') {
                isWord = true;
            } else {
                if (isWord) {
                    isWord = false;
                    len = 0;
                }
                len++;
            }
        }
        return len;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLastWord("Hello World") << endl;
    cin.get();
    return 0;
}
