#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main () {
    long long m = -1, aux;

    for(int i=9; i>0; i--) {
        vector<char> n(i);
        for(int j=1; j<=i; j++) n[j-1] = j+48;
        sort(n.begin(), n.end());

        do {
            string s(n.begin(), n.end());

            aux = stoi(s);
            if(aux < m) continue;
            bool isPrime = true;
            for (int k = 2; k <= aux / 2; ++k) {
                if (aux % k == 0) {
                    isPrime = false;
                    break;
                }
            }

            if(isPrime && aux > m) m = aux;
        } while ( next_permutation(n.begin(), n.end()) );
        if(m != -1) break;
    }

    cout << m << endl;

    return 0;
}
