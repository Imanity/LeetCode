#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    int num[] = { 4, 5, 6, 7, 0, 1, 2 };
    vector<int> nums(&num[0], &num[7]);
    Solution s;
    cout << s.search(nums, 6) << endl;
    cin.get();
    return 0;
}
