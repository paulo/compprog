#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    // long addition of binary numbers
    int getSum(int a, int b) {
        // 2 : 0 0 1 0
        // 3 : 0 0 1 1
        // 5 : 0 1 0 1

        int i = 0;
        int t = 0;
        int aux;
        while (i < 4) {
            aux = 1 << i;
            // cout << aux << endl;
            // cout << (aux & a & b) << endl;
            // cout << ((aux & b) ^ (aux & a)) << endl;
            t = t | ((aux & b) ^ (aux & a)) << i;
            // cout << t << endl;
            // cout << (aux & a & b) << endl;
            // cout << (((aux & a) && (aux & b)) << (i + 1)) << endl;
            t = t | (((aux & a) && (aux & b)) << (i + 1));
            // cout << t << endl;

            i++;
        }

        return t;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << Solution().getSum(3, 3) << endl;

    return 0;
}
