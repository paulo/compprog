#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) m[target - nums[i]] = i;
        for (int i = 0; i < nums.size(); i++)
            if (m.find(nums[i]) != m.end() && m[nums[i]] != i) {
                return vector<int>({i, m[nums[i]]});
            }

        return vector<int>();
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {2, 7, 11, 15};

    for (auto x : Solution().twoSum(nums, 9)) cout << x << endl;

    return 0;
}
