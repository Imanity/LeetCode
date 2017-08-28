#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        int max_num = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (left[nums[i]] || right[nums[i]]) {
                continue;
            }
            int left_num = left[nums[i] - 1];
            int right_num = right[nums[i] + 1];
            int curr = 1;
            if (left_num && right_num) {
                left[nums[i]] = left_num + 1;
                right[nums[i]] = right_num + 1;
                right[nums[i] - left_num] = left[nums[i] + right_num] = left_num + right_num + 1;
                curr = left_num + right_num + 1;
            } else if (left_num) {
                right[nums[i]] = 1;
                right[nums[i] - left_num] = left[nums[i]] = left_num + 1;
                curr = left_num + 1;
            } else if (right_num) {
                left[nums[i]] = 1;
                left[nums[i] + right_num] = right[nums[i]] = right_num + 1;
                curr = right_num + 1;
            } else {
                left[nums[i]] = right[nums[i]] = 1;
            }
            max_num = max_num > curr ? max_num : curr;
        }
        return max_num;
    }
};

int main() {
    int num[] = { 100, 4, 200, 1, 3, 2 };
    vector<int> nums(&num[0], &num[6]);
    Solution s;
    cout << s.longestConsecutive(nums) << endl;
    cin.get();
    return 0;
}
