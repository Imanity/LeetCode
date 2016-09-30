#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() <= 2 && nums2.size() <= 2) {
			if (nums1.size() == 2) {
			}
		}
		vector<int>::iterator nums1Mid = nums1.begin() + nums1.size() / 2;
		vector<int>::iterator nums2Mid = nums2.begin() + nums2.size() / 2;
		vector<int> v1, v2;
		if (*nums1Mid < *nums2Mid) {
			v1.assign(nums1Mid, nums1.end());
			v2.assign(nums2.begin(), nums2Mid + 1);
		} else {
			v1.assign(nums1.begin(), nums1Mid + 1);
			v2.assign(nums2Mid, nums2.end());
		}
		return findMedianSortedArrays(v1, v2);
	}
};

int main() {
	int a[] = { 1, 3 };
	int b[] = { 2 };
	vector<int> aList(&a[0], &a[2]);
	vector<int> bList(&b[0], &b[1]);
	Solution sol;
	cout << sol.findMedianSortedArrays(aList, bList) << endl;
	return 0;
}
