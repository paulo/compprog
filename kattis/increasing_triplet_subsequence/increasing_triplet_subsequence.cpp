#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;

        int mi = INT_MAX, ma = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mi && nums[i] > ma) return true;

            if (nums[i] <= mi) {
                mi = nums[i];
            } else if (nums[i] <= ma) {
                ma = nums[i];
            }
        }

        return false;
    }
};

#define pb push_back

int main() {
    vector<int> nums = {20, 100, 10, 12, 5, 13};

    cout << Solution().increasingTriplet(nums) << endl;

    return 0;
}
