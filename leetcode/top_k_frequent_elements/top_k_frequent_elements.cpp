#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) freq[nums[i]]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for (auto x : freq) {
            pq.push({x.second, x.first});
        }

        vector<int> res(k);
        for (int i = 0; i < k; i++) {
            res[i] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    auto res = Solution().topKFrequent(nums, k);

    for (auto x : res) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
