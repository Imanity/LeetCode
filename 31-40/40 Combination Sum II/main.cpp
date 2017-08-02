#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res = combinationSum1(candidates, target);
        vector<vector<int> > noDupRes;
        for(int i = 0; i < res.size(); ++i) {
            bool isDup = false;
            for(int j = 0; j < noDupRes.size(); ++j) {
                if(noDupRes[j].size() == res[i].size()) {
                    bool tmp = true;
                    for(int k = 0; k < noDupRes[j].size(); ++k) {
                        if(noDupRes[j][k] != res[i][k]) {
                            tmp = false;
                        }
                    }
                    if(tmp) {
                        isDup = true;
                        break;
                    }
                } else {
                    continue;
                }
            }
            if(!isDup) {
                noDupRes.push_back(res[i]);
            }
        }
        return noDupRes;
    }
    vector<vector<int> > combinationSum1(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> tmp;
        for(int i = 0; i < candidates.size(); ++i) {
            if(candidates[i] == target) {
                tmp.push_back(target);
                break;
            }
        }
        if(tmp.size() != 0) {
            res.push_back(tmp);
        }
        if(candidates.size() != 0 && candidates[0] <= target / 2) {
            int i = 0, j = 0;
            while(i < candidates.size() && candidates[i] <= target / 2) {
                while(j < candidates.size() && candidates[j] <= target - candidates[i]) {
                    ++j;
                }
                vector<int> tmpCan;
                for(int k = i + 1; k < j; ++k) {
                    tmpCan.push_back(candidates[k]);
                }
                vector<vector<int> > tmpRes = combinationSum1(tmpCan, target - candidates[i]);
                for(int k = 0; k < tmpRes.size(); ++k) {
                    if(tmpRes[k].size() != 0) {
                        tmpRes[k].push_back(candidates[i]);
                        res.push_back(tmpRes[k]);
                    }
                }
                ++i;
            }
        }
        return res;
    }
};

int main() {
    int num[] = { 10, 1, 2, 7, 6, 1, 5 };
    vector<int> nums(&num[0], &num[7]);
    Solution s;
    vector<vector<int> > res = s.combinationSum2(nums, 8);
    cout << "count: " << res.size() << endl;
    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
