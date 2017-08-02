#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<string> strings;
        vector<vector<string> > res;
        for(int i = 0; i < strs.size(); ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            int j = 0;
            for(j = 0; j < strings.size(); ++j) {
                if(strings[j] == str) {
                    break;
                }
            }
            if(j == strings.size()) {
                strings.push_back(str);
                vector<string> tmp;
                tmp.push_back(strs[i]);
                res.push_back(tmp);
            } else {
                res[j].push_back(strs[i]);
            }
        }
        return res;
    }
};

int main() {
    string str[] = { "eat", "tea", "tan", "ate", "nat", "bat" };
    vector<string> strs(&str[0], &str[6]);
    Solution s;
    vector<vector<string> > res = s.groupAnagrams(strs);
    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
