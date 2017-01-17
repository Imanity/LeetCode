#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxLength = 0, currentLength = 0;
		for (int i = 0; i < s.length(); ++i) {
			char tmp = s[i];
			currentLength++;
			for (int j = i - 1; j >= i - currentLength && j >= 0; --j) {
				if (s[j] == tmp) {
					currentLength = i - j;
					break;
				}
			}
			if (currentLength > maxLength) {
				maxLength = currentLength;
			}
		}
		return maxLength;
	}
};

int main() {
	Solution sol;
	cout << sol.lengthOfLongestSubstring("abcabcbb");
	cin.get();
	return 0;
}
