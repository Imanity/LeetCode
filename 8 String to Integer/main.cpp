#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int result = 0;
		int mark = 1;
		int spaceNum = 0;
		for (unsigned i = 0; i < str.length(); ++i)	{
			if (str[i] == ' ') {
				spaceNum++;
			} else {
				break;
			}
		}
		str = str.substr(spaceNum, str.length() - spaceNum);
		if (str.length() >= 1 && str[0] == '-') {
			mark = -1;
			str = str.substr(1, str.length() - 1);
		} else if (str.length() >= 1 && str[0] == '+') {
			mark = 1;
			str = str.substr(1, str.length() - 1);
		}
		for (unsigned i = 0; i < str.length(); ++i) {
			if (str[i] < '0' || str[i] > '9') {
				break;
			}
			if (result > (INT_MAX - (str[i] - '0')) / 10) {
				return mark == -1 ? INT_MIN : INT_MAX;
			}
			result = result * 10 + (str[i] - '0');
		}
		return result * mark;
	}
};

int main() {
	Solution sol;
	cout << sol.myAtoi("010") << endl;
	return 0;
}
