#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int result = 0;
        vector<int>::iterator itr = nums.begin();
        while (itr != nums.end()) {
            if(*itr == val) {
                itr = nums.erase(itr);
            } else {
                result++;
                itr++;
            }
        }
        return result;
    }
};

int main() {
    int num[] = { 1, 1, 2, 3, 4, 4, 5 };
    vector<int> nums(&num[0], &num[7]);
    Solution s;
    cout << s.removeElement(nums, 4) << endl;
    for(int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << "\t";
    }
    cin.get();
    return 0;
}
