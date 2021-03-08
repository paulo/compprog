#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i = 0; i < n; i++)
#define reps(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define w(n) while (cin >> n)
#define pl(n) cout << n << endl

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    deque<int> qmin, qmax;
    int diff = INT_MAX;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        while (!qmin.empty() && v[i] < v[qmin.back()]) qmin.pop_back();
        if (!qmin.empty() && qmin.front() <= i - k) qmin.pop_front();
        qmin.pb(i);

        while (!qmax.empty() && v[i] > v[qmax.back()]) qmax.pop_back();
        if (!qmax.empty() && qmax.front() <= i - k) qmax.pop_front();
        qmax.pb(i);

        if (i >= k - 1) diff = min(diff, v[qmax.front()] - v[qmin.front()]);
    }

    cout << diff << endl;

    return 0;
}
