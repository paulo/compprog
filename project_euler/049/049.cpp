#include <iostream>
#include <algorithm>

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
    string s1, s2, s3;
    for(int i = 1000; i < 7000; i++) {
        if(isPrime(i) && isPrime(i+3330) && isPrime(i+6660)) {
            s1 = to_string(i);
            s2 = to_string(i+3330);
            s3 = to_string(i+6660);

            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            sort(s3.begin(), s3.end());

            if(s1 == s2 && s2 == s3) cout << i << ' ' << i+3330 << ' ' << i+6660 << endl;
        }
    }
}
