#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == 'M') {
                result += 1000;
            } else if(s[i] == 'D') {
                result += 500;
            } else if(s[i] == 'C') {
                if(i != s.length() - 1 && (s[i + 1] == 'M' || s[i + 1] == 'D')) {
                    result += s[i + 1] == 'M' ? 900 : 400;
                    i++;
                } else {
                    result += 100;
                }
            } else if(s[i] == 'L') {
                result += 50;
            } else if(s[i] == 'X') {
                if(i != s.length() - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                    result += s[i + 1] == 'C' ? 90 : 40;
                    i++;
                } else {
                    result += 10;
                }
            } else if(s[i] == 'V') {
                result += 5;
            } else if(s[i] == 'I') {
                if(i != s.length() - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                    result += s[i + 1] == 'X' ? 9 : 4;
                    i++;
                } else {
                    result += 1;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.romanToInt("MMMCMLXXXVII") << endl;
    cin.get();
    return 0;
}
