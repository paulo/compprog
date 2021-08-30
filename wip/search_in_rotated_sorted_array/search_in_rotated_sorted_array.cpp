#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;

        if (nums.size() == 1 && nums[0] != target) return -1;

        while (l <= r) {  // find smallest element
            mid = (l + r) / 2;

            if (nums[l] >= nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // cout << mid << endl;

        int m = mid, t = nums.size();
        l = m;
        r = l == 0 ? nums.size() - 1 : l - 1;
        int ll, rr;
        while (nums[l] <= nums[r]) {
            ll = l - m;
            if (ll < 0) ll = t + ll;
            rr = r - m;
            if (rr < 0) rr = t + rr;

            mid = (((ll + rr) / 2) + m) % t;
            // if (mid < 0) mid = t + mid;
            // cout << ll << " " << mid << " " << rr << endl;

            if (nums[mid] == target) return mid;

            if (nums[mid] > target) {
                r = mid - 1;
                if (r < 0) r = t + r;
            } else {
                l = (mid + 1) % t;
            }
        }

        return -1;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // vector<int> nums = {1, 3};
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    cout << Solution().search(nums, 0) << endl;

    return 0;
}
