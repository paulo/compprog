#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;

        int i = 0;
        for (i = 0; i < nums.size(); i++) {
            sum -= i;
            sum += nums[i];
        }
        sum -= i;

        return -sum;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 9};
    cout << Solution().missingNumber(nums) << endl;

    return 0;
}
