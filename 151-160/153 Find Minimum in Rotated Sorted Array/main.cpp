#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int left = 0, right = nums.size() - 1, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

int main() {
    int num[] = { 4,5,6,7,0,1,2 };
    vector<int> nums(&num[0], &num[7]);
    Solution s;
    cout << s.findMin(nums) << endl;
    return 0;
}
