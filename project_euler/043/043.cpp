#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

typedef long long ll;

int primes[] = {2, 3, 5, 7, 11, 13, 17};

bool subdiv(string n) {
    for(int i=0; i < 7; i++) {
        if(stoi(n.substr(i+1, 3)) % primes[i] != 0) return false;
    }

    return true;
}

int main () {
    char cs[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    sort(cs, cs+10);

    ll total = 0;
    do {
        string s(cs, 10);
        if(subdiv(s)) total += stoll(s);
    } while ( next_permutation(cs, cs+10) );

    cout << total << endl;

    return 0;
}
