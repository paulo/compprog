#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

struct pair_compare {
    // If the ratio is the same, we want to order by population number
    // The lower number of ballot boxes is given priority (or the higher population)
    bool operator() (const pair<int,int>& p1, const pair<int,int>& p2) const {
        if(ceil(p1.first / double(p1.second)) == ceil(p2.first / double(p2.second))){
            return p1.first < p2.first;
        }
        return ceil(p1.first / double(p1.second)) < ceil(p2.first / double(p2.second));
    }
};

int main() {
    int n, b;

    while(cin >> n >> b && !(n == -1 || b == -1)) {
        int ci;

        vector<pair<int, int>> pii(n);
        for(int i = 0; i < n; i++) {
           cin >> ci;
           pii[i] = make_pair(ci, 1);
           b--;
        }

        make_heap(pii.begin(), pii.end(), pair_compare());

        while(b>0) {
            pair<int,int> h = pii.front();
            pop_heap(pii.begin(),pii.end(), pair_compare()); pii.pop_back();

            pii.push_back(make_pair(h.first, h.second + 1));
            push_heap(pii.begin(),pii.end(), pair_compare());
            b--;
        }

        pair<int,int> res = pii.front();
        cout << ceil(res.first / double(res.second)) << endl;
    }
}
