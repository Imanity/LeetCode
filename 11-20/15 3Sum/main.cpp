#include <iostream>
#include <vector>
#include <tr1/unordered_map>
#include <algorithm>
using namespace std;
using namespace std::tr1;

class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        unordered_map<int, int> hmap;
        vector< vector<int> > result;
        sort(nums.begin(), nums.end());
        int tmp = 0, tmp1 = 0;
        bool isInit = true, isInit1 = true;
        int left = -1, right = -1;
        for(int i = 0; i < nums.size(); ++i) {
            hmap[nums[i]]++;
            if(nums[i] < 0) {
                left = i;
            }
            if(nums[i] <= 0) {
                right = i + 1;
            }
        }
        // 0 + 0 + 0
        if(hmap[0] >= 3) {
            int tmpArr[3] = { 0, 0, 0 };
            vector<int> tmp(&tmpArr[0], &tmpArr[3]);
            result.push_back(tmp);
        }
        // x + x + (-2x)
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == tmp && !isInit) {
                continue;
            } else {
                isInit = false;
                tmp = nums[i];
            }
            if(nums[i] != 0 && hmap[nums[i]] >= 2) {
                if(hmap[- 2 * nums[i]] != 0) {
                    int tmpArr[3] = { nums[i], nums[i], - 2 * nums[i] };
                    vector<int> tmp(&tmpArr[0], &tmpArr[3]);
                    result.push_back(tmp);
                }
            }
        }
        isInit = true;
        // x + 0 + y
        if(hmap[0] != 0) {
            for(int i = 0; i < nums.size(); ++i) {
                if(nums[i] >= 0) {
                    break;
                }
                if(nums[i] == tmp && !isInit) {
                    continue;
                } else {
                    isInit = false;
                    tmp = nums[i];
                }
                if(hmap[- nums[i]] != 0) {
                    int tmpArr[3] = { nums[i], 0, - nums[i] };
                    vector<int> tmp(&tmpArr[0], &tmpArr[3]);
                    result.push_back(tmp);
                }
            }
        }
        isInit = true;
        // x + y + z, x < 0, y < 0
        for(int i = 0; i <= left; ++i) {
            if(nums[i] == tmp && !isInit) {
                continue;
            } else {
                isInit = false;
                tmp = nums[i];
                isInit1 = true;
            }
            for(int j = i + 1; j <= left; ++j) {
                if(nums[j] == tmp1 && !isInit1) {
                    continue;
                } else {
                    isInit1 = false;
                    tmp1 = nums[j];
                }
                int tmpNum = - (nums[i] + nums[j]);
                if(nums[i] != nums[j] && hmap[tmpNum] > 0) {
                    int tmpArr[3] = { nums[i], nums[j], tmpNum };
                    vector<int> tmp(&tmpArr[0], &tmpArr[3]);
                    result.push_back(tmp);
                }
            }
        }
        isInit = true;
        isInit1 = true;
        // x + y + z, y > 0, z > 0
        for(int i = right; i < nums.size(); ++i) {
            if(nums[i] == tmp && !isInit) {
                continue;
            } else {
                isInit = false;
                tmp = nums[i];
                isInit1 = true;
            }
            for(int j = i + 1; j < nums.size(); ++j) {
                if(nums[j] == tmp1 && !isInit1) {
                    continue;
                } else {
                    isInit1 = false;
                    tmp1 = nums[j];
                }
                int tmpNum = - (nums[i] + nums[j]);
                if(nums[i] != nums[j] && hmap[tmpNum] > 0) {
                    int tmpArr[3] = { nums[i], nums[j], tmpNum };
                    vector<int> tmp(&tmpArr[0], &tmpArr[3]);
                    result.push_back(tmp);
                }
            }
        }
        return result;
    }
};

int main() {
    int num[] = { -4, -1, -4, 0, 2, -2, -4, -3, 2, -3, 2, 3, 3, -4 };
    vector<int> nums(&num[0], &num[14]);
    Solution s;
    vector< vector<int> > result = s.threeSum(nums);
    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
