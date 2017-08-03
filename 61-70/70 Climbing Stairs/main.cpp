#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) {
            return n;
        }
        vector<int> stairs;
        stairs.push_back(1);
        stairs.push_back(2);
        for (int i = 2; i < n; ++i) {
            stairs.push_back(stairs[i - 2] + stairs[i - 1]);
        }
        return stairs[n - 1];
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(44) << endl;
    cin.get();
    return 0;
}
