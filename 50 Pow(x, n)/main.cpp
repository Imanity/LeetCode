#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) {
            if(n == INT_MIN) {
                return (1 / x) / myPow(x, -(n + 1));
            }
            return 1 / myPow(x, -n);
        }
        if(n == 1) {
            return x;
        }
        if(n == 0) {
            return 1;
        }
        if(n % 2 == 0) {
            double tmp = myPow(x, n / 2);
            return tmp * tmp;
        } else {
            double tmp = myPow(x, n / 2);
            return tmp * tmp * x;
        }
    }
};

int main() {
    Solution s;
    cout << s.myPow(0.00001, -2147483648) << endl;
    cin.get();
}
