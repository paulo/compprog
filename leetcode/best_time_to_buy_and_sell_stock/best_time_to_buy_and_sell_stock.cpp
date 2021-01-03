#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        long minPrice = INT_MAX;
        int profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else if (prices[i] - minPrice > profit) {
                profit = prices[i] - minPrice;
            }
        }

        return profit;
    }

    // NOTE: Dynprog solution that I couldn't quite memoize efficiently
    // int profit(vector<int>& prices, int i, int curr) {
    // if (i == prices.size() - 1 && curr == -1) return 0;
    // if (i == prices.size() - 1) return prices[i] - curr;

    // int res = 0;
    // if (curr != -1) {
    // res = max(res, prices[i] - curr);             // sell this day
    // res = max(res, profit(prices, i + 1, curr));  // dont sell this day
    // } else {
    // res = max(res, profit(prices, i + 1, prices[i]));  // buy this day
    // res = max(res, profit(prices, i + 1, curr));  // dont buy this day
    // }

    // return res;
    // }
};

int main() {
    vector<int> prices{2, 1, 2, 1, 0, 1, 2};

    cout << Solution().maxProfit(prices) << endl;

    return 0;
}
