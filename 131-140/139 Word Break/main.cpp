#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> arr(s.size(), false);
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < wordDict.size(); ++j) {
                bool isSuffix = true;
                if (wordDict[j].size() > i + 1) {
                    continue;
                }
                for (int k = 0; k < wordDict[j].size(); ++k) {
                    if (s[i + 1 - wordDict[j].size() + k] != wordDict[j][k]) {
                        isSuffix = false;
                        break;
                    }
                }
                if (!isSuffix) {
                    continue;
                }
                if (i == wordDict[j].size() - 1 || arr[i - wordDict[j].size()]) {
                    arr[i] = true;
                    break;
                }
            }
        }
        return arr[s.size() - 1];
    }
};

int main() {
    Solution s;
    vector<string> dict;
    dict.push_back("a");
    dict.push_back("abc");
    dict.push_back("b");
    dict.push_back("cd");
    cout << s.wordBreak("abcd", dict) << endl;
    return 0;
}
