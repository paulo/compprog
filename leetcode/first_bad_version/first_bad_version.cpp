#include <iostream>

using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
   public:
    int firstBadVersion(int n) {
        int min = 1, max = n, aux;
        while (min < max) {
            aux = min + (max - min) / 2;
            if (isBadVersion(aux)) {
                max = aux;
            } else {
                min = aux + 1;
            }
        }

        return min;
    }
};

int main() { return 0; }
