#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) {
            x = -x;
        }
        if (x <= 1) {
            return x;
        }
        for (int i = 0; i <= x / 2 + 1; ++i) {
            if (i * i > x || i * i < 0) {
                return i - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.mySqrt(1) << endl;
    cin.get();
    return 0;
}
