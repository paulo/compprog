#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int iSize = nums.size(), current = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[current] == nums[i]) {
                iSize--;
            } else {
                current++;
                nums[current] = nums[i];
            }
        }

        return iSize;
    }
};

int main() { return 0; }
