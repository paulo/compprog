#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

// Pending optimization
class Solution {
  public:
   vector<vector<int>> threeSum(vector<int>& nums) {
      if (nums.size() <= 2) {
         return vector<vector<int>>();
      }

      unordered_map<int, int> m;
      vector<int> clean;
      for (int i = 0; i < nums.size(); i++) {
         m[nums[i]]++;
         if (m[nums[i]] >= 3) continue;
         clean.push_back(nums[i]);
      }

      vector<vector<int>> res;
      int a, b, c, d;

      map<vector<int>, bool> mem_res;
      for (int i = 0; i < clean.size() - 1; i++) {
         for (int j = i + 1; j < clean.size(); j++) {
            a = clean[i];
            b = clean[j];
            c = -(a + b);
            d = m[c];

            if (d == 0) continue;
            if ((c == a || c == b) && d < 2) continue;
            if (a == b && b == c && d < 3) continue;

            if (a > b) swap(a, b);
            if (b > c) swap(b, c);
            if (a > b) swap(a, b);

            vector<int> newV = vector<int>{a, b, c};

            if (mem_res.find(newV) != mem_res.end()) continue;
            mem_res[newV] = true;

            res.push_back(newV);
         }
      }
      return res;
   }
};

int main() {
   vector<int> v{-1, 0, 1, 2, -1, -4};
   Solution s = Solution();

   vector<vector<int>> trips = s.threeSum(v);

   for (int i = 0; i < trips.size(); i++) {
      for (int j = 0; j < trips[i].size(); j++) {
         cout << trips[i][j] << ' ';
      }

      cout << endl;
   }

   return 0;
}
