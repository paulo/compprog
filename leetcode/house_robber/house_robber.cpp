#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
    int m[100][40010];

   public:
    int rob(vector<int>& nums) { return robber(nums, 0, nums.size() - 1); }

    int robber(vector<int>& nums, int curr, int i) {
        if (i < 0) return curr;

        if (m[i][curr] != -1) return m[i][curr];

        int mx = 0;
        mx = max(mx, robber(nums, curr + nums[i], i - 2));  // rob this house
        mx = max(mx, robber(nums, curr, i - 1));  // not rob this house

        m[i][curr] = mx;

        return mx;
    }

    Solution() { memset(m, -1, 100 * 40010 * sizeof(int)); }
};

int main() {
    vector<int> nums{2, 7, 9, 3, 1};
    // vector<int> nums{1, 2, 3, 1};

    cout << Solution().rob(nums) << endl;

    return 0;
}
