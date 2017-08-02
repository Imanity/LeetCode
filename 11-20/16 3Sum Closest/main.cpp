#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int numlen = nums.size();
        if(numlen < 3) {
            return -1;
        }
        sort(nums.begin(), nums.end());
        int minGap = nums[0] + nums[1] + nums[2] - target;
        for(int i = 0; i <= numlen - 3; i++) {
            int begin = i + 1;
            int end = numlen - 1;
            while(begin < end) {  
                int curGap = nums[i] + nums[begin] + nums[end] - target;
                if(curGap == 0) {
                    return target;
                }
                if(abs(curGap) < abs(minGap)) {
                    minGap = curGap;
                }
                if(curGap < 0) {
                    begin++;
                } else {
                    end--;
                }
            }
        }
        return target + minGap;
    }
};

int main() {
    int num[] = { -1, 2, 1, -4 };
    vector<int> nums(&num[0], &num[4]);
    Solution s;
    cout << s.threeSumClosest(nums, 1) << endl;
    cin.get();
    return 0;
}
