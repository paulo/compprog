#include <iostream>

using namespace std;

// I - 1
// V - 5
// X - 10
// L - 50
// C - 100
// D - 500
// M - 1000

// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.

class Solution {
   public:
    int romanToInt(string s) {
        int i = 0, c = 0;

        int pi = 0, px = 0, pc = 0;
        while (i < s.length()) {
            switch (s[i]) {
                case 'I':
                    pi++;
                    break;
                case 'V':
                    c += 5 - pi;
                    pi = 0;
                    break;
                case 'X':
                    if (pi) {
                        c += 10 - pi;
                        pi = 0;
                    } else {
                        px++;
                    }
                    break;
                case 'L':
                    c += 50 - px * 10;
                    px = 0;
                    break;
                case 'C':
                    if (px) {
                        c += 100 - 10 * px;
                        px = 0;
                    } else {
                        pc++;
                    }
                    break;
                case 'D':
                    c += 500 - pc * 100;
                    pc = 0;
                    break;
                case 'M':
                    c += 1000 - pc * 100;
                    pc = 0;
                    break;
            }
            i++;
        }

        c += pi;
        c += 10 * px;
        c += 100 * pc;

        return c;
    }
};

int main() {
    cout << Solution().romanToInt("MCMXCIV") << endl;

    return 0;
}
