#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;

        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i]]) return true;
            m[nums[i]] = true;
        }

        return false;
    }
};

int main() { return 0; }
