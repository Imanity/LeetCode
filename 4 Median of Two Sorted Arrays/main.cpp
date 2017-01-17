#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		if (m > n) {
			return findMedianSortedArrays(nums2, nums1);
		}
		int minidx = 0, maxidx = m;
		int i, j;
		int num1, mid = (m + n + 1) >> 1, num2;
		while (minidx <= maxidx) {
			i = (minidx + maxidx) >> 1;
			j = mid - i;
			if (i < m && j > 0 && nums2[j - 1] > nums1[i]) {
				minidx = i + 1;
			} else if (i > 0 && j < n && nums2[j] < nums1[i - 1]) {
				maxidx = i - 1;
			} else {
				if (i == 0) {
					num1 = nums2[j - 1];
				} else if (j == 0) {
					num1 = nums1[i - 1];
				} else {
					num1 = max(nums1[i - 1], nums2[j - 1]);
				}
        		break;
			}
		}
		if ((m + n) & 1) {
			return num1;
		}
		if (i == m) {
			num2 = nums2[j];
		} else if (j == n) {
			num2 = nums1[i];
		} else {
			num2 = min(nums1[i], nums2[j]);
		}
		return (num1 + num2) / 2.;
	}
};

int main() {
	int a[4] = { 1, 3, 5, 7 };
	int b[2] = { 2, 4 };
	vector<int> aList(&a[0], &a[4]);
	vector<int> bList(&b[0], &b[2]);
	Solution sol;
	cout << sol.findMedianSortedArrays(aList, bList) << endl;
	cin.get();
	return 0;
}
