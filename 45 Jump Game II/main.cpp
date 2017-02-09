#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int farPos = 0;
        for(int i = 0; i < n - 1; ++i) {
            int tmp = farPos;
            for(int j = i; j <= farPos; ++j) {
                tmp = (j + nums[j]) > tmp ? (j + nums[j]) : tmp;
                if(tmp >= n - 1) {
                    return i + 1;
                }
            }
            farPos = tmp;
        }
        return n - 1;
    }
};

int main() {
    int num[] = { 5,9,3,2,1,0,2,3,3,1,0,0 };
    vector<int> nums(&num[0], &num[12]);
    Solution s;
    cout << s.jump(nums) << endl;
    cin.get();
    return 0;
}