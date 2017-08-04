#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0;
        for (int k = 0; k < nums.size(); ++k) {
            int tmp = nums[k];
            nums[k] = 2;
            if (tmp <= 1) {
                nums[j] = 1;
                ++j;
                if (tmp == 0) {
                    nums[i] = 0;
                    ++i;
                }
            }
        }
    }
};

int main() {
    int num[] = { 2, 1, 1, 2, 0 };
    vector<int> nums(&num[0], &num[5]);
    Solution s;
    s.sortColors(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << "\t";
    }
    cout << endl;
    cin.get();
    return 0;
}
