#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// From https://algo.is/aflv16/aflv_06_dynamic_programming.pdf
class Solution {
    unordered_map<int, int> m;

   public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            res = max(res, maxSum(nums, i));
        }

        return res;
    }

    int maxSum(vector<int>& nums, int i) {
        if (i == 0) return nums[i];

        if (m.find(i) != m.end()) {
            return m[i];
        }

        m[i] = max(nums[i], nums[i] + maxSum(nums, i - 1));

        return m[i];
    }

    Solution() { m = unordered_map<int, int>(); }
};

int main() {
    vector<int> nums{-1, -2};

    cout << Solution().maxSubArray(nums) << endl;

    return 0;
}
