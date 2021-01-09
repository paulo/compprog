#include <iostream>
#include <vector>

using namespace std;

class Vector2D {
    int d1, d2;
    bool hasN;
    vector<vector<int>> v;

   public:
    Vector2D(vector<vector<int>>& _v) {
        d1 = 0;
        d2 = 0;
        hasN = false;
        v = _v;

        travelNext();
    }

    int next() {
        int res = v[d1][d2];

        d2++;
        travelNext();
        return res;
    }

    bool hasNext() { return hasN; }

   private:
    void travelNext() {
        hasN = false;
        while (d1 < v.size()) {
            if (d2 < v[d1].size()) {
                hasN = true;
                break;
            } else {
                d1++;
                d2 = 0;
            }
        }
    }
};

int main() {
    // vector<vector<int>> v{vector<int>{1, 2}, vector<int>{3}, vector<int>{4}};
    vector<vector<int>> v{vector<int>{}, vector<int>{3}};
    Vector2D* obj = new Vector2D(v);
    bool param_2 = obj->hasNext();
    int param_1 = obj->next();
    bool param_3 = obj->hasNext();

    return 0;
}
