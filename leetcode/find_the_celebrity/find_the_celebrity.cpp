#include <bits/stdc++.h>

using namespace std;

/* The knows API is defined for you.
      bool knows(int a, int b); */

bool knows(int a, int b) { return true; }

class Solution {
   public:
    int findCelebrity(int n) {
        int l = 0;

        for (int i = 1; i < n; i++) {
            if (knows(i, l)) {
                continue;
            } else {
                l = i;
            }
        }

        for (int i = 0; i < l; i++) {
            if (!knows(i, l)) return -1;
        }

        for (int i = 0; i < n; i++) {
            if (i == l) continue;

            if (knows(l, i)) return -1;
        }

        return l;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << Solution().findCelebrity(2) << endl;

    return 0;
}
