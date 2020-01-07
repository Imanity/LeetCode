#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int s = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s ^= nums[i];
        }
        return s;
    }
};

int main() {
    int input[] = { 4, 1, 2, 1, 2 };
    vector<int> inputs(input, input + 5);
    Solution s;
    cout << s.singleNumber(inputs) << endl;
}
