#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

const int n0[1][1] = {{1}};
const int n1[2][2] = {{1, 1}, {1, -1}};

void had(ll n, ll x, ll y, ll w, ll h) {
    if(n==0) return;
    if(n==1) {


    } else {

    }

    sqrt(n);

    return;
}

int main() {
    int t;
    cin >> t;

    ll n, x, y, w, h;
    for(int i = 0; i < t; i++){
        cin >> n >> x >> y >> w >> h;

        ll ns = sqrt(n);

        had(ns, x, y, w, h);

    }

    return 0;
}
