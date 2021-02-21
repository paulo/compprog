#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

class Solution {
    vector<bool> chosen;
    vector<int> current;
    vector<vector<int>> res;

   public:
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums);
        return res;
    }

    void perm(vector<int>& nums) {
        if (current.size() == nums.size()) {
            vector<int> r(current.size());
            for (int i = 0; i < int(nums.size()); i++) {
                r[i] = current[i];
            }

            res.push_back(r);
        } else {
            for (int i = 0; i < int(nums.size()); i++) {
                if (chosen[i]) continue;

                chosen[i] = true;
                current.push_back(nums[i]);
                perm(nums);
                chosen[i] = false;
                current.pop_back();
            }
        }
    }

    Solution() {
        chosen = vector<bool>(6, false);
        current = vector<int>();
        res = vector<vector<int>>();
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = vector<int>{1, 2, 3};

    vector<vector<int>> v = Solution().permute(nums);

    for (auto vx : v) {
        for (int i : vx) {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}
