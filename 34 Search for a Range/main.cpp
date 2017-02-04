#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid = -1;
        vector<int> res;
        if(l > r || nums[l] > target || nums[r] < target) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        while(l < r) {
            mid = (l + r) / 2;
            if(nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                int lm = (l + mid) / 2;
                int rm = (r + mid) / 2;
                if(nums[lm] < target) {
                    l = lm + 1;
                }
                if(nums[rm] > target) {
                    r = rm - 1;
                }
                break;
            }
        }
        for(int i = l; i <= r; ++i) {
            if(nums[i] < target) {
                l = i + 1;
            }
        }
        for(int i = r; i >= l; --i) {
            if(nums[i] > target) {
                r = i - 1;
            }
        }
        if(l > r) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        res.push_back(l);
        res.push_back(r);
        return res;
    }
};

int main() {
    int num[] = { 5, 7, 7, 8, 8, 10 };
    vector<int> nums(&num[0], &num[6]);
    Solution s;
    vector<int> res = s.searchRange(nums, 8);
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << "\t";
    }
    cin.get();
    return 0;
}
