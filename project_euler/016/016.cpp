#include<iostream>
#include<math.h>
#include<cstring>

using namespace std;

const int MAXN = 1000;

int main() {
    int n[MAXN];
    memset(n, 0, MAXN * sizeof(int));
    n[0] = 1; // 2 ^ 0

    // long multiplication
    int aux, maxj = 0;
    for(int i=0; i<1000; i++) {
        int j=0, left = 0;

        while(j <= maxj) {
            aux = n[j] * 2;
            aux += left;
            left = aux / 10;
            n[j] = aux % 10;
            maxj = max(maxj, j+left);
            j++;
        }
    }

    long long total = 0;
    for(int i=maxj; i >= 0; i--) total += n[i];

    cout << total << endl;
}
