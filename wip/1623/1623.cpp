#include <bits/stdc++.h>

using namespace std;

vector<int> nums;

int dp(int i, int n, int curr) {
    if (curr < 0) return INT_MAX;
    if (i >= n) return curr;
    if (curr == 0) return curr;

    int m = INT_MAX;
    m = min(m, dp(i + 1, n, curr - nums[i]));
    m = min(m, dp(i + 1, n, curr));

    return m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int aux;
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        total += aux;
        nums.push_back(aux);
    }

    int res = dp(0, n, total / 2 + 1);
    int totalaux = total / 2 + 1 - res;
    total -= total / 2 + 1;
    cout << abs(totalaux - total) << endl;

    return 0;
}
