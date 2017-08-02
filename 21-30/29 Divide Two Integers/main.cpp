#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0, sign = 1;
        if(divisor == 0) {
            return INT_MAX;
        }
        if(dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if(dividend > 0 && divisor > 0) {
            dividend = -dividend;
            divisor = -divisor;
        } else if(dividend > 0) {
            sign = -1;
            dividend = -dividend;
        } else if(divisor > 0) {
            sign = -1;
            divisor = -divisor;
        }
        while(dividend < 0) {
            for(int i = 0; i < 32; ++i) {
                if((divisor << i) < dividend || (divisor << i) >= 0) {
                    if(i == 0) {
                        dividend = 0;
                    } else {
                        dividend -= (divisor << (i - 1));
                        result += (1 << (i - 1));
                    }
                    break;
                }
            }
        }
        if(sign == 1) {
            return result;
        } else {
            return -result;
        }
    }
};

int main() {
    Solution s;
    cout << s.divide(INT_MIN, -1) << endl;
    cin.get();
    return 0;
}
