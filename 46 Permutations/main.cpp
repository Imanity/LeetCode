#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.size() == 1) {
            vector<int> num;
            num.push_back(nums[0]);
            res.push_back(num);
            return res;
        }
        for(int i = 0; i < nums.size(); ++i) {
            vector<int> tmp;
            for(int j = 0; j < i; ++j) {
                tmp.push_back(nums[j]);
            }
            for(int j = i + 1; j < nums.size(); ++j) {
                tmp.push_back(nums[j]);
            }
            vector<vector<int> > resTmp = permute(tmp);
            for(int j = 0; j < resTmp.size(); ++j) {
                vector<int> single(resTmp[j].begin(), resTmp[j].end());
                single.push_back(nums[i]);
                res.push_back(single);
            }
        }
        return res;
    }
};

int main() {
    int num[] = { 1, 2, 3 };
    vector<int> nums(&num[0], &num[3]);
    Solution s;
    vector<vector<int> > res = s.permute(nums);
    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}