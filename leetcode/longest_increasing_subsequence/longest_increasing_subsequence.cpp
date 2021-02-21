#include <climits>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int m[2510][2510];
    const int INF = 100000000;

   public:
    int lengthOfLIS(vector<int>& nums) { return len(nums, 0, -INF); }

    int len(vector<int>& nums, int i, int prev) {
        if (i >= int(nums.size())) return 0;
        if (prev > 0 && m[i][prev] != -1) return m[i][prev];

        int mx = 0;
        // not choosing this number in the subsequence
        mx = max(mx, len(nums, i + 1, prev));
        // choosing this number in the subsequence
        if (prev < 0 || nums[i] > nums[prev]) {
            mx = max(mx, 1 + len(nums, i + 1, i));
        }

        if (prev >= 0) m[i][prev] = mx;

        return mx;
    }

    Solution() { memset(m, -1, 2510 * 2510 * sizeof(int)); }
};

int main() {
    vector<int> v{10, 9, 2, 5, 3, 7, 101, 18};
    // vector<int> v{0, 1, 0, 3, 2, 3};
    // vector<int> v{7, 7, 7, 7, 7, 7, 7};
    // vector<int> v{4, 10, 4, 3, 8, 9};

    cout << Solution().lengthOfLIS(v) << endl;

    return 0;
}
