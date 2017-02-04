#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid = -1;
        if(r == -1 || nums[l] >= target) {
            return 0;
        }
        if(nums[r] < target) {
            return (r + 1);
        }
        while(r - l > 1) {
            mid = (l + r) / 2;
            if(nums[mid] < target) {
                l = mid;
            } else if(nums[mid] > target) {
                r = mid;
            } else {
                return mid;
            }
        }
        return r;
    }
};

int main() {
    int num[] = { 1, 3 };
    vector<int> nums(&num[0], &num[2]);
    Solution s;
    cout << s.searchInsert(nums, 3) << endl;
    cin.get();
    return 0;
}