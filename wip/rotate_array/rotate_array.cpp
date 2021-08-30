#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0 || nums.size() == k) return;
        if (nums.size() <= 1) return;

        for (int i = 0; i < nums.size(); i++) {
            swap(nums[i % k], nums[(i + k) % nums.size()]);

            // for (auto x : nums) cout << x << " ";
            // cout << endl;
        }

        if (nums.size() % k == 0) return;
        for (int i = 0, j = k % nums.size() - 1; i < j; i++, j--) {
            swap(nums[i % nums.size()], nums[j % nums.size()]);
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {1, 2};
    // vector<int> nums = {-1, -100, 3, 99};
    // vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    for (auto x : nums) cout << x << " ";
    cout << endl;

    Solution().rotate(nums, 3);

    for (auto x : nums) cout << x << " ";
    cout << endl;

    return 0;
}
