#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<vector<int> > > arr(s.size(), vector<vector<int> >());
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
                if (i == wordDict[j].size() - 1) {
                    arr[i].push_back(vector<int>(1, j));
                } else {
                    for (int k = 0; k < arr[i - wordDict[j].size()].size(); ++k) {
                        vector<int> tmp(arr[i - wordDict[j].size()][k]);
                        tmp.push_back(j);
                        arr[i].push_back(tmp);
                    }
                }
            }
        }
        vector<string> res;
        for (int i = 0; i < arr[s.size() - 1].size(); ++i) {
            string str;
            for (int j = 0; j < arr[s.size() - 1][i].size(); ++j) {
                str += wordDict[arr[s.size() - 1][i][j]];
                if (j != arr[s.size() - 1][i].size() - 1) {
                    str += " ";
                }
            }
            res.push_back(str);
        }
        return res;
    }
};

int main() {
    Solution s;
    string wordDict[] = {"apple", "pen", "applepen", "pine", "pineapple"};
    vector<string> dict(wordDict, wordDict + 5);
    vector<string> res = s.wordBreak("pineapplepenapple", dict);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    return 0;
}
