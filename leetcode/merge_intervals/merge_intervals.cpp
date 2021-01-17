#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> v{intervals[0]};

        for (int i = 1; i < intervals.size(); i++) {
            if (cld(v[v.size() - 1], intervals[i])) {
                v[v.size() - 1] = unite(v[v.size() - 1], intervals[i]);
            } else {
                v.push_back(intervals[i]);
            }
        }

        return v;
    }

    // Collides if not both of them are bigger or smaller
    bool cld(vector<int> v1, vector<int> v2) {
        return !((v1[0] > v2[1] && v1[1] > v2[0]) ||
                 (v2[0] > v1[1] && v2[1] > v1[0]));
    }

    vector<int> unite(vector<int> v1, vector<int> v2) {
        int mi = min(v1[0], v2[0]);
        int ma = max(v1[1], v2[1]);

        return vector<int>{mi, ma};
    }
};

int main() {
    vector<vector<int>> v{
        vector<int>{1, 3},
        vector<int>{2, 6},
        vector<int>{8, 10},
        vector<int>{15, 18},
    };

    vector<vector<int>> r = Solution().merge(v);

    for (auto p : r) cout << p[0] << " " << p[1] << endl;

    return 0;
}
