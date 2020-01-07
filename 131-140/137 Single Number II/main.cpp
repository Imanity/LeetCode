#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                sum += !!(nums[j] & (1 << i));
            }
            res <<= 1;
            res |= !!(sum % 3);
        }
        return res;
    }
};

int main() {
    int input[] = { -2, -2, 1, 1, -3, 1, -3, -3, -4, -2 };
    vector<int> inputs(input, input + 10);
    Solution s;
    cout << s.singleNumber(inputs) << endl;
}
