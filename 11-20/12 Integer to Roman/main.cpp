#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> digits;
        int bits = 0;
        string result;
        while(num > 0) {
            digits.push_back(num % 10);
            num /= 10;
            bits++;
        }
        if(bits == 4) {
            for(int i = 0; i < digits[3]; ++i) {
                result.push_back('M');
            }
        }
        string w3[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string w2[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string w1[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        if(bits >= 3) {
            result += w3[digits[2]];
        }
        if(bits >= 2) {
            result += w2[digits[1]];
        }
        if(bits >= 1) {
            result += w1[digits[0]];
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.intToRoman(3987) << endl;
    cin.get();
    return 0;
}
