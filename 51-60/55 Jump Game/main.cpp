#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end_pos = nums.size() - 1;
        while(true) {
            if(nums[0] >= end_pos) {
                return true;
            }
            bool isFound = false;
            for(int i = end_pos - 1; i > 0; --i) {
                if(nums[i] >= (end_pos - i)) {
                    end_pos = i;
                    isFound = true;
                    break;
                }
            }
            if(!isFound) {
                return false;
            }
        }
        return false;
    }
};

int main() {
    int num[] = { 0, 2, 3 };
    vector<int> nums(&num[0], &num[3]);
    Solution s;
    cout << s.canJump(nums);
    cin.get();
    return 0;
}
