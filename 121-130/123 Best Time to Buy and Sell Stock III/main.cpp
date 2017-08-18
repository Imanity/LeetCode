#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - prices[i - 1] > 0) {
                profit += (prices[i] - prices[i - 1]);
            }
        }
        return profit;
    }
};

int main() {
    int price[] = { 7, 1, 5, 3, 6, 4 };
    vector<int> prices(&price[0], &price[6]);
    Solution s;
    cout << s.maxProfit(prices) << endl;
    cin.get();
    return 0;
}
