#include <iostream>

using namespace std;

bool isPrime(int n) {
    if(n == 1) return false;

    bool isPrime = true;
    for (int k = 2; k <= n / 2; ++k) {
        if (n % k == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

// can be optimised since first and last number must be primes (2, 3, 5, 7)
// 23, 37, 53, 73, 313, 317, 373, 797, 3137, 3797, 739397
int main() {
    int c = 0, total = 0;

    string s, aux;
    for(int i=11; c < 11; i++){
        s = to_string(i);
        if(!isPrime(i)) continue;

        bool allPrime = true;
        for(int j=1; j<s.size(); j++) {
            aux = s.substr(0, j);
            if(!isPrime(stoi(aux))) allPrime = false;
        }
        if(!allPrime) continue;
        for(int j=s.size()-1; j>0; j--) {
            aux = s.substr(j, s.size());
            if(!isPrime(stoi(aux))) allPrime = false;
        }

        if(!allPrime) continue;

        c++;
        total+=i;
    }

    cout << total << endl;
}
