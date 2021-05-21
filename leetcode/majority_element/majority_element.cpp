#include <bits/stdc++.h>

using namespace std;

// Algorithm assumes that there's a majority element
// If this assumption is not true, a second pass has
// to be performed
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0], c = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maj) {
                c++;
            } else {
                // Even if maj here is the true majority element,
                // by disregarding this prefix, we are ignoring an equal number
                // of majority and minority elements - therefore, maj will still
                // be the majority element in the suffix formed by throwing away
                // the first prefix.
                c--;
                if (c == 0) {
                    maj = nums[i];
                    c = 1;
                }
            }
        }

        return maj;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << Solution().majorityElement(nums) << endl;

    return 0;
}
