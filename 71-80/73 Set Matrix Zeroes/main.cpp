#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        bool firstRowZero = false;
        bool firstColZero = false;
        for (int i = 0; i < matrix.size(); ++i) {
            if (!matrix[i][0]) {
                firstColZero = true;
            }
        }
        for (int i = 0; i < matrix[0].size(); ++i) {
            if (!matrix[0][i]) {
                firstRowZero = true;
            }
        }
        for (int i = 1; i < matrix.size(); ++i) {
            bool isZero = false;
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (!matrix[i][j]) {
                    isZero = true;
                }
            }
            if (isZero) {
                matrix[i][0] = 0;
            }
        }
        for (int j = 1; j < matrix[0].size(); ++j) {
            bool isZero = false;
            for (int i = 0; i < matrix.size(); ++i) {
                if (!matrix[i][j]) {
                    isZero = true;
                }
            }
            if (isZero) {
                matrix[0][j] = 0;
            }
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (!matrix[0][j] || !matrix[i][0]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstRowZero) {
            for (int i = 0; i < matrix[0].size(); ++i) {
                matrix[0][i] = 0;
            }
        }
        if (firstColZero) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    int table[4][4] = {{1,2,3,4},{5,0,5,2},{8,9,2,0},{5,7,2,1}};
    vector<vector<int> > matrix;
    for (int i = 0; i < 4; ++i) {
        vector<int> line(&table[i][0], &table[i][4]);
        matrix.push_back(line);
    }
    Solution s;
    s.setZeroes(matrix);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
