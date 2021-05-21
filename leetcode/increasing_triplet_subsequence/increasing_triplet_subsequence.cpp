#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;

        int first = INT_MAX, second = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= first) {  // must be <= to consume the equal values,
                                     // else the second variable can be updated
                                     // to the same value as the first.
                                     // Also, doesn't really matter if we update
                                     // first after we've updated second, as the
                                     // condition first < second will still hold
                first = nums[i];
            } else if (nums[i] <= second) {
                second = nums[i];
            } else {
                return true;
            }
        }

        return false;
    }
};

// class Solution {
// public:
// bool increasingTriplet(vector<int>& nums) {
// if (nums.size() < 3) return false;

// vector<int> mins(nums.size(), INT_MAX);
// vector<int> maxs(nums.size(), INT_MIN);

// int mi = INT_MAX, ma = INT_MIN;
// for (int i = 0; i < nums.size(); i++) {
// mins[i] = min(nums[i], mi);
// mi = min(nums[i], mi);
// }

// for (int i = nums.size() - 1; i >= 0; i--) {
// maxs[i] = max(nums[i], ma);
// ma = max(nums[i], ma);
// }

// for (int i = 1; i < nums.size() - 1; i++) {
// if (mins[i - 1] < nums[i] && maxs[i + 1] > nums[i]) return true;
// }

// return false;
// }
// };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // vector<int> nums = {2, 1, 5, 0, 4, 6};
    vector<int> nums = {20, 100, 10, 12, 5, 13};
    // vector<int> nums = {0, 4, 1, -1, 2};
    cout << Solution().increasingTriplet(nums) << endl;

    return 0;
}
