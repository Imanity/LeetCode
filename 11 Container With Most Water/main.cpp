#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int s = 0;
        while(i < j) {
            int tmp = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
            s = s > tmp ? s : tmp;
            if(height[i] < height[j]) {
                int k = i;
                while(k < j && height[k] <= height[i]) {
                    k++;
                }
                i = k;
            } else {
                int k = j;
                while(k > i && height[k] <= height[j]) {
                    k--;
                }
                j = k;
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    int height[] = {1, 2, 3, 4, 5, 6, 7};
    vector<int> hVec(&height[0], &height[7]);
    cout << s.maxArea(hVec) << endl;
    cin.get();
    return 0;
}
