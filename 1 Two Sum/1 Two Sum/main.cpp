#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		for (unsigned int i = 0; i < nums.size(); ++i) {
			for (unsigned int j = i + 1; j < nums.size(); ++j) {
				if (nums[i] + nums[j] == target) {
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}
		return result;
	}
};

int main() {
	int inputArray[] = { 2, 7, 11, 15 };
	int target = 9;
	vector<int> input(&inputArray[0], &inputArray[3]);
	Solution sol;
	vector<int> result = sol.twoSum(input, target);
	for (unsigned int i = 0; i < result.size(); ++i) {
		cout << result[i] << "\t";
	}
	return 0;
}
