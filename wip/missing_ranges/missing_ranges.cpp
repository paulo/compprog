#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;

        int j = 0;
        while (nums[j] < lower && j < nums.size()) j++;
        if (nums.size() == j) {
            res.push_back(to_string(lower) + "->" + to_string(upper));
            return res;
        }

        for (int i = lower; i < upper; i++) {
            if (nums[j] == i) {
                j++;
            } else {
                while (j < nums.size())
                    ;
            }
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {0, 1, 3, 50, 75};
    int lower = 0, upper = 99;

    for (auto x : Solution().findMissingRanges(nums, lower, upper)) {
        cout << x << endl;
    };

    return 0;
}
