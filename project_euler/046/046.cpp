#include <iostream>
#include <math.h>
#include <unordered_map>
#include <vector>

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


int main() {
    vector<int> squares;
    vector<int> primes;
    unordered_map<int, bool> possibilities;

    // precompute possible numbers
    for(int i = 1; i <1000; i++) squares.push_back(2 * pow(i, 2));
    for(int i = 1; i <20000; i++) if(isPrime(i)) primes.push_back(i);

    for(int i = 0; i < primes.size(); i++) {
        for(int j = 0; j < squares.size(); j++) {
            possibilities[primes[i] + squares[j]] = true;
        }
    }

    for(int i=9; ; i+=2) {
        if(possibilities.find(i) == possibilities.end() && !isPrime(i)){
            cout << i << endl;
            break;
        }
    }
    return 0;
}
