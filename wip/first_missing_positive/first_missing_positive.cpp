#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) return 1;

        int mi = nums[0], ma = nums[0];

        for (auto n : nums) {
            if (n > 0) {
                 
            }
        }

        if (m) }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {7, 8, 9, 11, 12};

    cout << Solution().firstMissingPositive(nums) << endl;

    return 0;
}
