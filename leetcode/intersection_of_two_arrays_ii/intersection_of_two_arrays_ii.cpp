#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1;
        for (int i = 0; i < nums1.size(); i++) {
            m1[nums1[i]]++;
        }

        unordered_map<int, int> m2;
        for (int i = 0; i < nums2.size(); i++) {
            m2[nums2[i]]++;
        }

        vector<int> t;
        for (auto x : m1) {
            t.insert(t.end(), min(x.second, m2[x.first]), x.first);
        }

        return t;
    }
};

int main() { return 0; }
