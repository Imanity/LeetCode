#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> codes;
        if (n == 1) {
            codes.push_back(0);
            codes.push_back(1);
            return codes;
        }
        vector<int> tmp = grayCode(n - 1);
        for (int i = 0; i < tmp.size(); ++i) {
            codes.push_back(tmp[i]);
        }
        for (int i = tmp.size() - 1; i >= 0; --i) {
            tmp[i] += pow(2, n - 1);
            codes.push_back(tmp[i]);
        }
        return codes;
    }
};

int main() {
    Solution s;
    vector<int> r = s.grayCode(3);
    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << endl;
    }
    cin.get();
    return 0;
}
