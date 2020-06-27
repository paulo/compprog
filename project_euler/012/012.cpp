#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

int main() {
    unordered_map<ll, ll> m;

    ll tri=0, i = 0;
    for(int k=1;; k++) {
        tri += k;
        ll c=0;
        for (int i=1;i<=sqrt(tri); i++) {
            if (tri%i==0) {
                if(tri/i == i) c++;
                else c+=2;
            }
        }

        cout << tri << ' ' << c << endl;
        if(c > 500) break;
    }
}
