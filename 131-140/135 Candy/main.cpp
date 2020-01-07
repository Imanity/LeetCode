#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) {
            return 1;
        }
        int max_num = 1, last_count = 1, last_num = 1, total_num = 1;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                last_num += 1;
                max_num = last_num;
                last_count = last_num == 1;
            } else if (ratings[i] == ratings[i - 1]) {
                last_num = 1;
                max_num = last_num;
                last_count = last_num == 1;
            } else {
                if (last_num > 1) {
                    last_num = 1;
                    last_count = 1;
                } else {
                    last_num = 1;
                    if (max_num == last_count + 1) {
                        total_num += max_num;
                        max_num += 1;
                    } else {
                        total_num += last_count;
                    }
                    last_count += 1;
                }
            }
            total_num += last_num;
        }
        return total_num;
    }
};

int main() {
    int rate[] = { 1, 6, 10, 8, 7, 3, 2 };
    vector<int> ratings(rate, rate + 7);
    Solution s;
    cout << s.candy(ratings) << endl;
}
