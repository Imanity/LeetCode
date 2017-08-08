#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element {
    int val;
    int num;
    Element(int v, int n) : val(v), num(n) {}
};

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<Element> table;
        int tmp = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (!table.size() || nums[i] != tmp) {
                Element newElement(nums[i], 1);
                table.push_back(newElement);
            } else {
                ++table[table.size() - 1].num;
            }
            tmp = nums[i];
        }
        vector<vector<int> > subsets;
        vector<int> current(table.size(), 0);
        int total = 1;
        for (int i = 0; i < table.size(); ++i) {
            total *= (table[i].num + 1);
        }
        for (int i = 0; i < total; ++i) {
            vector<int> subset;
            for (int j = 0; j < table.size(); ++j) {
                int tmp = 1;
                for (int k = j + 1; k < table.size(); ++k) {
                    tmp *= (table[k].num + 1);
                }
                int curr = 0;
                if (j == 0) {
                    curr = i / tmp;
                } else {
                    curr = (i % (tmp * (table[j].num + 1))) / tmp;
                }
                for (int k = 0; k < curr; ++k) {
                    subset.push_back(table[j].val);
                }
            }
            subsets.push_back(subset);
        }
        return subsets;
    }
};

int main() {
    int num[] = { 1, 2, 2, 3, 3, 3 };
    vector<int> nums(&num[0], &num[6]);
    Solution s;
    vector<vector<int> > subsets = s.subsetsWithDup(nums);
    for (int i = 0; i < subsets.size(); ++i) {
        for (int j = 0; j < subsets[i].size(); ++j) {
            cout << subsets[i][j] << " ";
        }
        cout << endl;
    }
    cin.get();
    return 0;
}
