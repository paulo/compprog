#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int g;
    string r;

    int low = -1, high = 11;
    while (cin >> g && g != 0) {
        cin >> r >> r;

        if (r == "high") {
            high = min(high, g);
        } else if (r == "low") {
            low = max(low, g);
        } else {
            if (g < high && g > low && high > low) {
                cout << "Stan may be honest" << endl;
            } else {
                cout << "Stan is dishonest" << endl;
            }
            low = -1, high = 11;
        }
    }

    return 0;
}
