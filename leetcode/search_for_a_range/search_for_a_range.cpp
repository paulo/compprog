#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};

        if (nums.size() == 0) return res;

        int l = 0, r = nums.size() - 1, mid;
        int leftMost = -1;
        while (l <= r) {
            mid = (l + r) / 2;

            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                leftMost = mid;
                r = mid - 1;  // keep searching to the left more
            }
        }

        if (leftMost > -1)
            res[0] = leftMost;
        else
            return res;

        l = leftMost;
        r = nums.size() - 1;
        int rightMost = -1;
        while (l <= r) {
            mid = (l + r) / 2;

            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                rightMost = mid;
                l = mid + 1;  // keep searching to the right more
            }
        }
        res[1] = rightMost;

        return res;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {2, 2};
    for (auto x : Solution().searchRange(nums, 2)) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
