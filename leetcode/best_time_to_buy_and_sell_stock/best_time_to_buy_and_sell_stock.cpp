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
};

int main() {
    vector<int> prices{2, 1, 2, 1, 0, 1, 2};

    cout << Solution().maxProfit(prices) << endl;

    return 0;
}
