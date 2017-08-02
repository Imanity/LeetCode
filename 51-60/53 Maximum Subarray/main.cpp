#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> newNums;
        int curr = 0;
        if(nums.size() == 1) {
            newNums.push_back(nums[0]);
        } else {
            for(int i = 0; i < nums.size(); ++i) {
                if(nums[i] > 0) {
                    if(curr < 0) {
                        curr = 0;
                    }
                    curr += nums[i];
                } else {
                    if(curr > 0) {
                        newNums.push_back(curr);
                    }
                    newNums.push_back(nums[i]);
                    curr = -1;
                }
            }
            if(curr >= 0) {
                newNums.push_back(curr);
            }
        }
        
        int n = newNums.size();
        int max = newNums[0];
        for(int i = 0; i < n; ++i) {
            int tmp = 0;
            for(int j = i; j < n; ++j) {
                tmp += newNums[j];
                if(tmp > max) {
                    max = tmp;
                }
            }
        }
        return max;
    }
};

int main() {
    int num[] = {-2,1,-3,4,-1,2,1,-5,4 };
    vector<int> nums(&num[0], &num[9]);
    Solution s;
    cout << s.maxSubArray(nums);
    cin.get();
    return 0;
}
