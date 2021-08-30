#include <bits/stdc++.h>

using namespace std;

long long int maxSubarraySum(vector<int> v, int n) {
    long long int res = INT_MIN, currentSum = 0;

    queue<int> q;
    for (int i = 0; i < n && i < v.size(); i++) {
        currentSum += v[i];
        q.push(v[i]);
        res = currentSum;
    }

    int prev;
    for (int i = n; i < v.size(); i++) {
        prev = q.front();
        q.pop();
        q.push(v[i]);

        currentSum += v[i] - prev;
        res = max(res, currentSum);
    }

    if (res == INT_MIN) return -1;

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v1 = {1, 2, 5, 2, 8, 1, 5};
    vector<int> v2 = {1, 2, 5, 2, 8, 1, 5};
    vector<int> v3 = {};
    vector<int> v4 = {-2, -3, 4, -1, -2, 1, 5, -3};
    vector<int> v5 = {-1, -1, 2, 1, 3, 4};
    vector<int> v6 = {3, -1, 4};

    cout << (maxSubarraySum(v1, 4) == 17) << endl;
    cout << (maxSubarraySum(v2, 2) == 10) << endl;
    cout << (maxSubarraySum(v3, 4) == -1) << endl;
    cout << (maxSubarraySum(v4, 5) == 7) << endl;
    cout << (maxSubarraySum(v5, 2) == 7) << endl;
    cout << (maxSubarraySum(v6, 2) == 3) << endl;

    return 0;
}
