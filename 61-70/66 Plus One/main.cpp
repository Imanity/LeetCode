#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        while (i >= 0) {
            if (digits[i] == 9) {
                digits[i] = 0;
                --i;
            } else {
                digits[i]++;
                break;
            }
        }
        if (i == -1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main() {
    vector<int> num;
    num.push_back(9);
    num.push_back(9);
    num.push_back(9);
    Solution s;
    num = s.plusOne(num);
    for (int i = 0; i < num.size(); ++i) {
        cout << num[i];
    }
    cout << endl;
    cin.get();
    return 0;
}
