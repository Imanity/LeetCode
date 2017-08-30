#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        return getPartition(s, 0);
    }
    vector<vector<string> > getPartition(string s, int i) {
        vector<vector<string> > res;
        if (i == s.size() - 1) {
            vector<string> line;
            line.push_back(s.substr(s.size() - 1));
            res.push_back(line);
            return res;
        }
        for (int j = i; j < s.size(); ++j) {
            if (isPalindrome(s, i, j)) {
                if (j == s.size() - 1) {
                    vector<string> line;
                    line.push_back(s.substr(i));
                    res.push_back(line);
                } else {
                    vector<vector<string> > r = getPartition(s, j + 1);
                    for (int k = 0; k < r.size(); ++k) {
                        r[k].insert(r[k].begin(), s.substr(i, j - i + 1));
                        res.push_back(r[k]);
                    }
                }
            }
        }
        return res;
    }
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<string> > p = s.partition("bb");
    for (int i = 0; i < p.size(); ++i) {
        for (int j = 0; j < p[i].size(); ++j) {
            cout << p[i][j] << "\t";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
