#include <bits/stdc++.h>

using namespace std;

int binSearch(vector<int> v, int x, bool lower_bound) {
    int left = 0, right = v.size() - 1, mid;

    while (left <= right) {
        mid = (right + left) / 2;

        if (v[mid] < x) {
            left = mid + 1;
        } else {
            if (lower_bound)
                right = mid - 1;
            else
                left = mid + 1;
        }
    }

    return mid;
}

int countX(vector<int> v, int x) {
    int upper = binSearch(v, x, false);
    int lower = binSearch(v, x, true);

    if (upper == v.size() - 1) upper++;
    return upper - lower;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v = {1, 1, 2, 2, 2, 2, 3};

    cout << binSearch(v, 2, true) << endl;
    cout << binSearch(v, 2, false) << endl;
    cout << (countX(v, 2) == 4) << endl;

    cout << countX(v, 3) << endl;
    cout << binSearch(v, 3, true) << endl;
    cout << binSearch(v, 3, false) << endl;

    return 0;
}
