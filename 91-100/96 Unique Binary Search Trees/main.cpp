#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> nums(n + 1, 0);
        nums[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                int left = nums[j - 1];
                int right = nums[i - j];
                if (left && right) {
                    nums[i] += (left * right);
                } else if (left) {
                    nums[i] += left;
                } else if (right) {
                    nums[i] += right;
                } else {
                    nums[i] += 1;
                }
            }
        }
        return nums[n];
    }
};

int main() {
    Solution s;
    cout << s.numTrees(3) << endl;
    cin.get();
    return 0;
}
