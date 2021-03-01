#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ml, k, l;
    for (int cs = 1; cs <= n; cs++) {
        cin >> ml >> k >> l;

        vi v(l);
        for (int i = 0; i < l; i++) cin >> v[i];

        sort(v.begin(), v.end(), greater<ll>());

        ll total = 0;
        for (ll i = 0, pos = 1; i < l && pos < ml + 1; pos++) {
            for (int j = 0; j < k && i < l; j++) {
                total += v[i] * pos;
                i++;
            }
        }

        cout << "Case #" << cs << ": " << total << endl;
    }

    return 0;
}
