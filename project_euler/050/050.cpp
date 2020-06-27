#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isPrime(int n) {
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
    vector<int> vprimes;
    unordered_map<int, bool> mprimes;

    for(int i=2; i < 1000000; i++) {
        if(isPrime(i)) {
            vprimes.push_back(i);
            mprimes[i] = true;
        }
    }

    // far from optimised but it works
    int maxprime=-1, maxc = -1;
    for(int i = 0; i < vprimes.size()-1; i++) {
        int sum = vprimes[i];
        int c = 1;
        for(int j = i+1; j < vprimes.size(); j++) {
            sum += vprimes[j];
            c++;
            if(sum >= 1000000) break;
            if(mprimes.find(sum) != mprimes.end() && c > maxc) {
                maxprime = sum;
                maxc = c;
            }
        }
    }

    cout << maxprime << '-' << maxc << endl;
}
