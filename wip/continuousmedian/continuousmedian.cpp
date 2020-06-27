#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
    int t;
    cin >> t;

    ll n;
    for(int i = 0; i < t; i++){
        cin >> n;

        vi m;
        ll a, total = 0;
        vi::iterator it;
        for(int j=0; j <n; j++){
            cin >> a;

            m.insert(it, a); // insert before iterator it

            if(j % 2 == 0) {
                total+=m[j/2];
            } else {
                total+= (m[j/2] + m[j/2+1]) / 2;
            }
        }

        cout << total << endl;
    }
}
