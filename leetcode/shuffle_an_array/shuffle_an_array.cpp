#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> nums, orig;

   public:
    Solution(vector<int>& _nums) {
        nums = _nums;
        orig = _nums;
        srand(time(NULL));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        nums = vector<int>(orig);
        return nums;
    }

    /** Returns a random shuffling of the array. */
    // https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
    // Have to be carefull with the numbers we consider for shuffling in order
    // to ensure a proper distribution (1/n probability of swapping each number)
    // The correctness of the algorithm follows from the fact that an element
    // (without loss of generality) is equally likely to be selected during all
    // iterations of the for loop. To prove this, observe that the probability
    // of a particular element ee being chosen on the kkth iteration (indexed
    // from 0) is simply P(eP(e being chosen during the kkth iteration)\cdot
    // P(e)⋅P(e not being chosen before the kkth iteration)).
    vector<int> shuffle() {
        for (int i = 0; i < nums.size(); i++) {
            swap(nums[i], nums[i + (rand() % (nums.size() - i))]);
        }

        return nums;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {1, 2, 3};

    Solution sol = Solution(nums);
    for (auto x : sol.shuffle()) {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : sol.reset()) {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : sol.shuffle()) {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : sol.reset()) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
