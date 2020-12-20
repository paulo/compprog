#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

vector<ll> divisors(ll n) {
    vector<ll> r;

    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are different, get both
            r.push_back(i);
            if (n / i != i) r.push_back(n / i);
        }
    }

    return r;
}

int main() {
    ll n;
    cin >> n;

    vector<ll> r = divisors(n);
    sort(r.begin(), r.end());

    for (int i = 0; i < r.size(); i++) {
        cout << r[i] - ll(1) << ' ';
    }
    cout << endl;

    return 0;
}
