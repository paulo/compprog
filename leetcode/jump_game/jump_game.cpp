#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    int m[30000];

   public:
    bool canJump(vector<int>& nums) { return jump(nums, 0); }

    bool jump(vector<int>& nums, int i) {
        if (i == int(nums.size()) - 1) return true;
        if (i > int(nums.size()) - 1) return false;
        if (nums[i] == 0) return false;
        if (i > 0 && nums[i] == nums[i - 1] - 1) return false;
        if (m[i] > -1) return m[i];

        int res = false;
        for (int j = 1; j <= nums[i]; j++) {
            res = res || jump(nums, i + j);
            if (res) break;
        }

        m[i] = res;

        return res;
    }

    Solution() { memset(m, -1, 30000 * sizeof(int)); };
};

int main() {
    // vector<int> v{2, 3, 1, 1, 4};
    vector<int> v{3, 2, 1, 0, 4};
    // vector<int> v{3, 0, 8, 2, 0, 0, 1};

    cout << Solution().canJump(v) << endl;
    return 0;
}
