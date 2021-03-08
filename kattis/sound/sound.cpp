#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i = 0; i < n; i++)
#define reps(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define w(n) while (cin >> n)
#define pl(n) cout << n << endl

// 0 1 1 2 3 2 2
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, c;
    cin >> n >> m >> c;

    vi v(n);
    rep(i, n) cin >> v[i];

    deque<int> qmin, qmax;  // init deques that track min and max
    vi res;
    for (int i = 0; i < n; i++) {
        // cout << v[i] << ' ' << v[i + m - 1] << endl;
        while (!qmin.empty() && v[i] < v[qmin.back()]) qmin.pop_back();
        if (!qmin.empty() && qmin.front() <= i - m) qmin.pop_front();
        qmin.pb(i);

        while (!qmax.empty() && v[i] > v[qmax.back()]) qmax.pop_back();
        if (!qmax.empty() && qmax.front() <= i - m) qmax.pop_front();
        qmax.pb(i);

        if (i >= m - 1 && v[qmax.front()] - v[qmin.front()] <= c)
            res.pb(i + 2 - m);  // +2 to compensate for index that starts at 1
    }

    // sort(res.begin(), res.end());
    if (res.empty())
        cout << "NONE" << endl;
    else
        for (auto r : res) cout << r << endl;

    return 0;
}
