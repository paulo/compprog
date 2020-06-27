#include <iostream>
#include <math.h>

using namespace std;

int primeFactors(int n) {
    int t = 0;

    if(n%2 == 0) t++;
    while (n%2 == 0) n = n/2; // divide by 2 until no longer posible

    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2) {
        if(n%i == 0) t++;
        while (n%i == 0) n = n/i; // While i divides n, divide n
    }

    // This condition is to handle the case when n is a prime number greater than 2
    if (n > 2) t++;

    return t;
}

int main() {
    int i = 1000;
    while(true) {
        bool noice = true;
        if(primeFactors(i) == 4) {
            for(int j=i+1; j < i+4; j++){
                if(primeFactors(j) != 4) noice = false;
            }
            if(noice) {
                cout << i << endl;
                break;
            }
        }


        i++;
    }
}
