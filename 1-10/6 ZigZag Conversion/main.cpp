#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		string result;
		if (numRows == 1) {
			return s;
		}
		int len = 2 * numRows - 2;
		vector< vector<char> > charArray(len / 2 + 1);
		for (int i = 0; i < s.size(); ++i) {
			charArray[len / 2 - abs(i % len - len / 2)].push_back(s[i]);
		}
		for (int i = 0; i < len / 2 + 1; ++i) {
			result.append(charArray[i].begin(), charArray[i].end());
		}
		return result;
	}
};

int main() {
	Solution sol;
	cout << sol.convert("PAYPALISHIRING", 3);
	cin.get();
	return 0;
}
