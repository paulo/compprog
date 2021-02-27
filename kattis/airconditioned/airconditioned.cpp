#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>  // smallest element at the top
        pq;

    int l, u;
    for (int i = 0; i < n; i++) {
        cin >> l >> u;
        pq.push(make_pair(u, l));
    }

    int t = 0, l2;
    while (!pq.empty()) {
        t++;
        u = pq.top().first;
        l = pq.top().second;
        pq.pop();

        while (!pq.empty()) {  // pop while minions fit on the same room
            l2 = pq.top().second;

            if (l2 <= u) {
                pq.pop();
            } else {
                break;
            }
        }
    }

    cout << t << endl;

    return 0;
}
