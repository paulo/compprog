#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int c[3] = {0, 0, 0};

        for (int i = 0; i < nums.size(); i++) c[nums[i]]++;
        int j = 0;
        for (int i = 0; i < 3; i++) {
            for (int k = 0; k < c[i]; k++) {
                nums[j++] = i;
            }
        }
    }
};

int main() { return 0; }
