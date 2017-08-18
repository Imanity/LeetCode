#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (numRows <= 0) {
            return res;
        }
        vector<int> firstLine(1, 1);
        res.push_back(firstLine);
        vector<int> line;
        for (int i = 1; i < numRows; ++i) {
            line.resize(0);
            line.push_back(1);
            for (int j = 1; j < i; ++j) {
                line.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
            line.push_back(1);
            res.push_back(line);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int> > rec = s.generate(5);
    for (int i = 0; i < rec.size(); ++i) {
        for (int j = 0; j < rec[i].size(); ++j) {
            cout << rec[i][j] << " ";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
