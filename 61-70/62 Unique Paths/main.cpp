#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int a = m + n - 2;
        long long int res = 1;
        if (m < n) {
            n = m;
        }
        for (int i = 0; i < n - 1; ++i) {
            res *= (a - i);
        }
        for (int i = 0; i < n - 1; ++i) {
            res /= (i + 1);
        }
        return res;
    }
};

int main () {
    Solution s;
    cout << s.uniquePaths(10, 10) << endl;
    cin.get();
    return 0;
}
