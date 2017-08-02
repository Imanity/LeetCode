#include <iostream>
#include <vector>
#include <tr1/unordered_map>
#include <algorithm>
using namespace std;
using namespace std::tr1;

struct Pair {
    int x;
    int y;
    Pair(int a, int b): x(a), y(b) {}
};

class Solution {
public:
    bool isValid(unordered_map<int, int> checkNum, vector<int> &single) {
        for(int i = 0; i < single.size(); ++i) {
            checkNum[single[i]]--;
            if(checkNum[single[i]] < 0) {
                return false;
            }
        }
        return true;
    }
    bool noRepeat(vector<int> &single, vector< vector<int> > &result) {
        for(int i = 0; i < result.size(); ++i) {
            bool tmp = true;
            for(int j = 0; j < result[i].size(); ++j) {
                if(single[j] != result[i][j]) {
                    tmp = false;
                }
            }
            if(tmp) {
                return false;
            }
        }
        return true;
    }
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
        unordered_map< int, vector<Pair> > hmap;
        vector<int> sums;
        vector< vector<int> > result;
        unordered_map<int, int> checkNum;
        unordered_map<int, int> repeatSum;
        for(int i = 0; i < nums.size(); ++i) {
            checkNum[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                hmap[nums[i] + nums[j]].push_back(Pair(nums[i], nums[j]));
                sums.push_back(nums[i] + nums[j]);
            }
        }
        int temp = 0;
        bool isInit = true;
        for(int i = 0; i < sums.size(); ++i) {
            if(repeatSum[sums[i]] != 0) {
                continue;
            } else {
                repeatSum[sums[i]] = 1;
                repeatSum[target - sums[i]] = 1;
            }
            if(hmap[sums[i]].size() != 0 && hmap[target - sums[i]].size() != 0) {
                for(int j = 0; j < hmap[sums[i]].size(); ++j) {
                    for(int k = 0; k < hmap[target - sums[i]].size(); ++k) {
                        vector<int> tmp;
                        tmp.push_back(hmap[sums[i]][j].x);
                        tmp.push_back(hmap[sums[i]][j].y);
                        tmp.push_back(hmap[target - sums[i]][k].x);
                        tmp.push_back(hmap[target - sums[i]][k].y);
                        sort(tmp.begin(), tmp.end());
                        if(isValid(checkNum, tmp) && noRepeat(tmp, result)) {
                            result.push_back(tmp);
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    int num[] = { 1,0,-1,0,-2,2 };
    vector<int> nums(&num[0], &num[6]);
    Solution s;
    vector< vector<int> > result = s.fourSum(nums, 0);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
