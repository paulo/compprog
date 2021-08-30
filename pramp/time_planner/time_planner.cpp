#include <bits/stdc++.h>

using namespace std;

// slotsA = [[10, 50], [60, 120], [140, 210]]
// slotsB = [[0, 15], [60, 70]]

vector<int> meetingPlanner(const vector<vector<int>>& slotsA,
                           const vector<vector<int>>& slotsB, int dur) {
    vector<int> res;
    int iA = 0, iB = 0;

    while (iA < slotsA.size() && iB < slotsB.size()) {
        int mi = max(slotsA[iA][0], slotsB[iB][0]);
        int ma = min(slotsA[iA][1], slotsB[iB][1]);

        if (ma - mi >= dur) {
            res = {mi, mi + dur};
            return res;
        }

        if (slotsB[iB][1] < slotsA[iA][1]) {
            iB++;
        } else {
            iA++;
        }
    }

    return res;
}

int main() {
    vector<vector<int>> slotsA = {{7, 12}};
    vector<vector<int>> slotsB = {{2, 11}};

    meetingPlanner(slotsA, slotsB, 5);
    return 0;
}
