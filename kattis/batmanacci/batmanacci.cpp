#include <iostream>
#include <unordered_map>

using namespace std;

typedef unsigned long long int ll;

int main() {
    ll k, n;
    cin >> n >> k;

    unordered_map<int, ll> lm;
    lm[0] = ll(0);
    lm[1] = ll(1);

    int i = 2;
    for(; i < n && lm[i-1] <= k; i++) lm[i] = lm[i-1] + lm[i-2];
    if(i % 2 != n % 2) i--; // if i is smaller than n (k is fullfiled sooner),
    // we must maintain parity between i and n so we're cutting from the same side
    // of the NANANAANAAN

    while(i > 2) {
        if(k > lm[i-2]) {
            k -= lm[i-2];
            i--;
        } else i-=2;
    }

    if(i==1) cout << 'N' << endl;
    else if(i==2) cout << 'A' << endl;

    return 0;
}
