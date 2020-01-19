#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int maxPos = 0, maxNeg = 0;
        int maxProduct = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                maxPos = max(nums[i], maxPos * nums[i]);
                maxNeg *= nums[i];
                maxProduct = max(maxPos, maxProduct);
            } else if (nums[i] < 0) {
                int tmp = maxPos;
                maxPos = maxNeg * nums[i];
                maxNeg = min(nums[i], tmp * nums[i]);
                maxProduct = max(maxPos, maxProduct);
            } else {
                maxPos = maxNeg = 0;
            }
        }
        return maxProduct;
    }
};

int main() {
    int num[] = { -2, 0, -1 };
    vector<int> nums(&num[0], &num[3]);
    Solution s;
    cout << s.maxProduct(nums) << endl;
    return 0;
}
