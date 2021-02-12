#include <math.h>

#include <iostream>

using namespace std;

typedef long long ll;

ll sum(ll n) {
    ll t = 0, aux, i = 1;
    while (n > 0) {
        aux = n % (ll)pow(10, i);
        n -= aux;
        t += aux / (ll)pow(10, i - 1);
        i++;
    }

    return t;
}

int main() {
    ll n;
    cin >> n;

    ll is = sum(n);

    while (true) {
        if (n % is == 0) break;
        n++;
        is = sum(n);
    }

    cout << n << endl;
    return 0;
}
