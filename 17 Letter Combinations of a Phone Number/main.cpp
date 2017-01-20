#include <iostream>
#include <string>
#include <vector>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

class Solution {
public:
    unordered_map<char, string> hmap;
    Solution() {
        hmap['2'] = "abc";
        hmap['3'] = "def";
        hmap['4'] = "ghi";
        hmap['5'] = "jkl";
        hmap['6'] = "mno";
        hmap['7'] = "pqrs";
        hmap['8'] = "tuv";
        hmap['9'] = "wxyz";
        hmap['0'] = " ";
    }
    vector<string> letterCombinations(string digits) {
        char ch = digits[0];
        vector<string> result;
        if(digits.length() == 0) {
            return result;
        }
        vector<string> sub = letterCombinations(digits.substr(1));
        if(sub.size() == 0) {
            for(int j = 0; j < hmap[ch].length(); ++j) {
                result.push_back(hmap[ch].substr(j, 1));
            }
        }
        for(int i = 0; i < sub.size(); ++i) {
            for(int j = 0; j < hmap[ch].length(); ++j) {
                result.push_back(hmap[ch].substr(j, 1) + sub[i]);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> res = s.letterCombinations("234");
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    cin.get();
    return 0;
}
