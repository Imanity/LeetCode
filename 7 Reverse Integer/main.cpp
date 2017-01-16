#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int result = 0;
		int mark = x > 0 ? 1 : -1;
		x = abs(x);
		while (x > 0) {
			int tmp = (INT_MAX - x % 10) / 10;
			if (result > tmp) {
				return 0;
			}
			result = result * 10 + x % 10;
			x /= 10;
		}
		return result * mark;
	}
};

int main() {
	Solution sol;
	cout << sol.reverse(-2147483412) << endl;
	return 0;
}
