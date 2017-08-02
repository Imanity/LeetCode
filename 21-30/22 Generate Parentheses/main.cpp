#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        genStr("", n, n, res);
        return res;
    }
    void genStr(string str, int left, int right, vector<string> &res) {
        if(left == 0 && right == 0) {
            res.push_back(str);
        }
        if(left > 0) {
            genStr(str + '(', left - 1, right, res);
        }
        if(right > 0 && left < right) {
            genStr(str + ')', left, right - 1, res);
        }
    }
};

int main() {
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    cin.get();
    return 0;
}
