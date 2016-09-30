#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int maxLength = 0;
		int maxPos = -1;
		bool isDouble = false;
		for (int i = 0; i < s.size(); i++) {
			int j = 0;
			while (i - j >= 0 && i + j < s.size()) {
				if (s[i - j] != s[i + j]) {
					break;
				}
				++j;
			}
			if ((j * 2 - 1) >= maxLength) {
				maxLength = j * 2 - 1;
				maxPos = i;
				isDouble = false;
			}
			j = 0;
			while (i - j >= 0 && i + j + 1 < s.size()) {
				if (s[i - j] != s[i + j + 1]) {
					break;
				}
				++j;
			}
			if ((j * 2) >= maxLength) {
				maxLength = j * 2;
				maxPos = i;
				isDouble = true;
			}
		}
		if (!isDouble) {
			return s.substr(maxPos - (maxLength - 1) / 2, maxLength);
		} else {
			return s.substr(maxPos - maxLength / 2 + 1, maxLength);
		}
	}
};

int main() {
	Solution sol;
	cout << sol.longestPalindrome("bb") << endl;
	return 0;
}
