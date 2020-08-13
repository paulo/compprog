#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll s, c, k;
    cin >> s >> c >> k;

    vector<ll> ss(s);
    for(int i = 0; i < s; i++) cin >> ss[i];

    sort(ss.begin(), ss.end(), greater<ll>());

    ll total = 0;
    for(int i = 0; i < s; i++) {
        ll cap = c;
        ll currColor = ss[i];
        while(i < s && cap > 0 && (currColor-ss[i]<=k)) {
            cap--;
            i++;
        }
        total++;
        i--;
    }

    cout << total << endl;

    return 0;
}
