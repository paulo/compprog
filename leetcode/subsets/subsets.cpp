#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        for (int i = 0; i < (1 << nums.size()); i++) {
            vector<int> sub;

            for (int j = 0; j < int(nums.size()); j++) {
                if (i & (1 << j)) sub.push_back(nums[j]);
            }
            v.push_back(sub);
        }

        return v;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> n = vector<int>{1, 2, 3};
    vector<vector<int>> v = Solution().subsets(n);

    for (auto vx : v) {
        for (int i : vx) {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}
