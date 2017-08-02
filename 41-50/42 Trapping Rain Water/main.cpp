#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int src = 0;
        for(int i = 0; i < height.size(); ++i) {
            src += height[i];
        }
        int maxHeight = 0;
        int left = -1, right = -1;
        for(int i = 0; i < height.size(); ++i) {
            if(height[i] >= maxHeight) {
                maxHeight = height[i];
                right = i;
            }
        }
        for(int i = 0; i < height.size(); ++i) {
            if(height[i] == maxHeight) {
                left = i;
                break;
            }
        }
        int lastHeight = 0;
        for(int i = 0; i < left; ++i) {
            if(height[i] < lastHeight) {
                height[i] = lastHeight;
            } else {
                lastHeight = height[i];
            }
        }
        lastHeight = 0;
        for(int i = height.size() - 1; i > right; --i) {
            if(height[i] < lastHeight) {
                height[i] = lastHeight;
            } else {
                lastHeight = height[i];
            }
        }
        for(int i = left; i < right; ++i) {
            height[i] = maxHeight;
        }
        int dst = 0;
        for(int i = 0; i < height.size(); ++i) {
            dst += height[i];
        }
        return (dst - src);
    }
};

int main() {
    int num[] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    vector<int> nums(&num[0], &num[12]);
    Solution s;
    cout << s.trap(nums) << endl;
    cin.get();
    return 0;
}
