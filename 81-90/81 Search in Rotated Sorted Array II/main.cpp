#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[l] < nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else if (nums[l] > nums[mid]) {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                ++l;
            }
        }
        return false;
    }
};

int main() {
    int num[] = { 4, 5, 6, 7, 0, 1, 2 };
    vector<int> nums(&num[0], &num[7]);
    Solution s;
    cout << s.search(nums, 4) << endl;
    cin.get();
    return 0;
}
