#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int tmp, result = 0, time = 0;
        bool isInit = true;
        vector<int>::iterator itr = nums.begin();
        while (itr != nums.end()) {
            if(!isInit && (*itr) == tmp) {
                ++time;
                isInit = false;
                if (time >= 2) {
                    itr = nums.erase(itr);
                } else {
                    result++;
                    itr++;
                }
            } else {
                time = 0;
                tmp = (*itr);
                result++;
                itr++;
                isInit = false;
            }
        }
        return result;
    }
};

int main() {
    int num[] = { 1, 1 };
    vector<int> nums(&num[0], &num[2]);
    Solution s;
    cout << s.removeDuplicates(nums) << endl;
    for(int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << "\t";
    }
    cin.get();
    return 0;
}
