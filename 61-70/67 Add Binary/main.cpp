#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        vector<int> res;
        string str;
        int i = a.size() - 1, j = b.size() - 1;
        int extra = 0;
        while (i >= 0 || j >= 0) {
            int curr = extra;
            if (i >= 0) {
                curr += a.at(i) - '0';
            }
            if (j >= 0) {
                curr += b.at(j) - '0';
            }
            if (curr <= 1) {
                extra = 0;
                res.push_back(curr);
            } else {
                extra = 1;
                res.push_back(curr - 2);
            }
            --i;
            --j;
        }
        if (extra != 0) {
            res.push_back(extra);
        }
        for (int i = res.size() - 1; i >= 0; --i) {
            str.push_back(res[i] + '0');
        }
        return str;
    }
};

int main() {
    Solution s;
    cout << s.addBinary("11", "1") << endl;
    cin.get();
    return 0;
}
