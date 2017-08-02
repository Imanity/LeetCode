#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") {
            return "0";
        }
        vector<int> resNum;
        string res;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int j = 0; j < num2.size(); ++j) {
            for(int i = 0; i < num1.size(); ++i) {
                if(i + j < resNum.size()) {
                    resNum[i + j] += (num1[i] - '0') * (num2[j] - '0');
                } else {
                    resNum.push_back((num1[i] - '0') * (num2[j] - '0'));
                }
            }
        }
        int carry = 0;
        for(int i = 0; i < resNum.size(); ++i) {
            resNum[i] += carry;
            carry = 0;
            if(resNum[i] >= 10) {
                carry = resNum[i] / 10;
                resNum[i] = resNum[i] % 10;
            }
        }
        if(carry > 0) {
            resNum.push_back(carry);
        }
        for(int i = resNum.size() - 1; i >= 0; --i) {
            res.push_back(resNum[i] + '0');
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.multiply("5", "12");
    cin.get();
    return 0;
}
