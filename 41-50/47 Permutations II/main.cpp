#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.size() == 1) {
            vector<int> num;
            num.push_back(nums[0]);
            res.push_back(num);
            return res;
        }
        sort(nums.begin(), nums.end());
        vector<int> noDup;
        int dupNum = -1;
        if(nums[0] == -1) {
            dupNum = -2;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == dupNum) {
                continue;
            }
            noDup.push_back(nums[i]);
            dupNum = nums[i];
        }
        for(int i = 0; i < noDup.size(); ++i) {
            vector<int> tmp(nums.begin(), nums.end());
            for(vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
                if(*it == noDup[i]) {
                    tmp.erase(it);
                    break;
                }
            }
            vector<vector<int> > resTmp = permuteUnique(tmp);
            for(int j = 0; j < resTmp.size(); ++j) {
                vector<int> single(resTmp[j].begin(), resTmp[j].end());
                single.push_back(noDup[i]);
                res.push_back(single);
            }
        }
        return res;
    }
};

int main() {
    int num[] = { 1, 1, 2 };
    vector<int> nums(&num[0], &num[3]);
    Solution s;
    vector<vector<int> > res = s.permuteUnique(nums);
    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
