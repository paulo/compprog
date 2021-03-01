#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<pair<ll, ll>> vii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    ll s, f;
    vii v(n);
    for (int i = 0; i < n; i++) {
        cin >> s >> f;
        v[i] = make_pair(f, s);
    }

    if (k >= n) {
        cout << n << endl;
        return 0;
    }

    // Sort by earliest finish first and then by earliest start
    sort(v.begin(), v.end());

    // stores the end time of the ongoing activity in each classroom.

    multiset<int> ms;

    // NOTE: Since we're using lower_bound and this returns the index of the
    // first number in the ms that is greater than or equal to the parameter
    // passed, and we're actually looking for the first ending time that is
    // smaller than the start time, we reverse the sign of the stored times
    // to get the wanted value on queries.

    ll total = 0;
    for (int i = 0; i < n; i++) {
        // look for classroom with activity that ends before or at the same time
        // than the start of the next event
        auto it = ms.lower_bound(-v[i].second);

        // if that classroom does not exist, try to add one
        if (it == ms.end()) {
            if (int(ms.size()) < k) {
                ms.insert(-v[i].first - 1);
                total++;
            }
            continue;
        }

        // remove previous event end time and add new event end time
        ms.erase(it);
        ms.insert(-v[i].first - 1);
        total++;
    }

    cout << total << endl;

    return 0;
}
