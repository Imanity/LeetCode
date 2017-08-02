#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m <= 0) {
            return res;
        }
        int n = matrix[0].size();
        if(n <= 0) {
            return res;
        }
        int dx = m - 1, dy = n - 1;
        int x = 0, y = -1;
        bool isInit = true;
        while(dx >= 0 && dy >= 0) {
            for(int i = 0; i <= dy; ++i) {
                y++;
                res.push_back(matrix[x][y]);
            }
            for(int i = 0; i < dx; ++i) {
                x++;
                res.push_back(matrix[x][y]);
            }
            if(dx > 0) {
                for(int i = 0; i < dy; ++i) {
                    y--;
                    res.push_back(matrix[x][y]);
                }
            }
            --dx;
            if(dy > 0) {
                for(int i = 0; i < dx; ++i) {
                    x--;
                    res.push_back(matrix[x][y]);
                }
            }
            --dx;
            dy -= 2;
        }
        return res;
    }
};

int main() {
    int list[5][5] = 
    {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25},
    };
    vector<vector<int> > board;
    for(int i = 0; i < 5; ++i) {
        vector<int> line;
        for(int j = 0; j < 5; ++j) {
            line.push_back(list[i][j]);
        }
        board.push_back(line);
    }
    Solution s;
    vector<int> res = s.spiralOrder(board);
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << "\t";
    }
    cin.get();
    return 0;
}
