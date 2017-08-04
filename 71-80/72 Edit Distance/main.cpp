#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > table;
        int m = word1.size();
        int n = word2.size();
        for (int i = 0; i <= m; ++i) {
            vector<int> line;
            for (int j = 0; j <= n; ++j) {
                line.push_back(-1);
            }
            table.push_back(line);
        }
        table[m][n] = 0;
        for (int i = m; i >= 0; --i) {
            for (int j = n; j >= 0; --j) {
                if (i == m && j == n) {
                    continue;
                }
                if (i < m && j < n && word1[i] == word2[j]) {
                    table[i][j] = table[i + 1][j + 1];
                } else {
                    int a = i < m ? table[i + 1][j] : -1;
                    int b = j < n ? table[i][j + 1] : -1;
                    int c = (i < m && j < n) ? table[i + 1][j + 1] : -1;
                    int min = -1;
                    if (a != -1 && (min == -1 || a < min)) {
                        min = a;
                    }
                    if (b != -1 && (min == -1 || b < min)) {
                        min = b;
                    }
                    if (c != -1 && (min == -1 || c < min)) {
                        min = c;
                    }
                    table[i][j] = min + 1;
                }
            }
        }
        return table[0][0];
    }
};

int main() {
    Solution s;
    cout << s.minDistance("edit", "distance") << endl;
    cin.get();
    return 0;
}
