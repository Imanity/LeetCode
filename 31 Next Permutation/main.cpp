#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) {
            return;
        }
        int pos = -1, tmp = -1;
        // Find the element to swap
        for(int i = nums.size() - 1; i >= 0; --i) {
            if(nums[i] >= tmp) {
                tmp = nums[i];
            } else {
                pos = i;
                break;
            }
        }
        if(pos == -1) {
            sort(nums.begin() + pos + 1, nums.end());
            return;
        }
        // Swap with the minimum value larger than the given element
        int min = INT_MAX, swap_pos;
        for(int i = pos; i < nums.size(); ++i) {
            if(nums[i] > nums[pos] && nums[i] < min) {
                swap_pos = i;
                min = nums[i];
            }
        }
        nums[swap_pos] = nums[pos];
        nums[pos] = min;
        // Reorder the rest elements
        sort(nums.begin() + pos + 1, nums.end());
    }
};

int main() {
    int num[] = { 4, 2, 4, 4, 3 };
    vector<int> nums(&num[0], &num[5]);
    Solution s;
    s.nextPermutation(nums);
    for(int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << "\t";
    }
    cin.get();
    return 0;
}
