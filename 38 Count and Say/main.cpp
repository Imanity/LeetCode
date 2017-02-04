#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) {
            return "1";
        }
        string str = countAndSay(n - 1);
        string res;
        int tmp = ' ', len = 0;
        for(int i = 0; i < str.length(); ++i) {
            if(str[i] == tmp) {
                len++;
            } else {
                if(len != 0) {
                    res.push_back(len + '0');
                    res.push_back(tmp);
                }
                tmp = str[i];
                len = 1;
            }
        }
        if(len != 0) {
            res.push_back(len + '0');
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(5) << endl;
    cin.get();
    return 0;
}