#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    void wiggleSort(vector<int>& nums) {
        vector<int> counts(5000, 0);

        for (int i = 0; i < nums.size(); i++) counts[nums[i]]++;
        for (int i = 0, j = 0; i < nums.size() && j < 5000;) {
            if (counts[j] > 0) {
                nums[i] = j;
                i++;
                counts[j]--;
            } else
                j++;
        }

        int mid = nums.size() / 2;
        if (nums.size() % 2 == 1) mid++;
        vector<int> helper = vector<int>(nums);

        for (int i = 0, j = 0; i < nums.size(); i++) {
            nums[i] = helper[j];
            if (i + 1 < nums.size()) nums[i + 1] = helper[mid];
            j++;
            i++;
            mid++;
        }

        // for (int i = 0; i < nums.size(); i++) {
        // if (i % 2 == 1) {
        // swap(nums[i], nums[mid]);
        // mid++;
        // } else {
        // nums[i] = prev;
        // prev = nums[i + 1];
        // }
        // }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // vector<int> nums = {1, 3, 2, 2, 3, 1};
    vector<int> nums = {1, 1, 2, 1, 2, 2, 1};

    Solution().wiggleSort(nums);

    for (int i = 0; i < nums.size(); i++) cout << nums[i] << endl;

    return 0;
}
