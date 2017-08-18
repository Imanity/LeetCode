#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            int j = 0;
            for (; j < i - 1; ++j) {
                row[j] += row[j + 1];
            }
            row[j] = 1;
            for (; j >= 0; --j) {
                row[j + 1] = row[j];
            }
            row[0] = 1;
        }
        return row;
    }
};

int main() {
    Solution s;
    vector<int> row = s.getRow(3);
    for (int i = 0; i < row.size(); ++i) {
        cout << row[i] << endl;
    }
    cin.get();
    return 0;
}
