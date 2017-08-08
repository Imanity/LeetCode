#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            for (vector<int>::iterator it = nums1.begin() + m; it != nums1.end();) {
                it = nums1.erase(it);
            }
            return;
        }
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                ++i;
            } else {
                nums1.insert(nums1.begin() + i, nums2[j]);
                ++i;
                ++j;
                ++m;
            }
        }
        for (vector<int>::iterator it = nums1.begin() + m; it != nums1.end();) {
            it = nums1.erase(it);
        }
        for (; j < n; ++j) {
            nums1.push_back(nums2[j]);
        }
    }
};

int main() {
    int num1[] = { 2, 0 };
    int num2[] = { 1 };
    vector<int> nums1(&num1[0], &num1[2]);
    vector<int> nums2(&num2[0], &num2[1]);
    Solution s;
    s.merge(nums1, 1, nums2, 1);
    for (int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    cin.get();
    return 0;
}
