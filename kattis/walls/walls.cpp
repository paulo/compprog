#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>

using namespace std;

int main() {
    int n, c;
    double l, w, r;
    cin >> l >> w >> n >> r;

    vector<vector<bool>> reach;

    pair<double, double> s1 = make_pair(l/double(2), double(0));
    pair<double, double> s2 = make_pair(-l/double(2), double(0));
    pair<double, double> s3 = make_pair(double(0), w/double(2));
    pair<double, double> s4 = make_pair(double(0), -w/double(2));

    double x, y;
    bool feasible[4];
    memset(feasible, false, sizeof(bool)*4);
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        c = 0;
        reach.push_back(vector<bool>(4, false));

        if((pow(x - s1.first, 2.0) + pow(y - s1.second, 2.0)) <= pow(r, 2.0)) {
            reach[i][0]=true; feasible[0] = true; c++;
        }
        if((pow(x - s2.first, 2.0) + pow(y - s2.second, 2.0)) <= pow(r, 2.0)) {
            reach[i][1]=true; feasible[1] = true; c++;
        }
        if((pow(x - s3.first, 2.0) + pow(y - s3.second, 2.0)) <= pow(r, 2.0)) {
            reach[i][2]=true; feasible[2] = true; c++;
        }
        if((pow(x - s4.first, 2.0) + pow(y - s4.second, 2.0)) <= pow(r, 2.0)) {
            reach[i][3]=true; feasible[3] = true; c++;
        }

        if(c == 4) {
            cout << "1" << endl;
            return 0;
        }
    }

    if(!feasible[0] || !feasible[1] || !feasible[2] || !feasible[3] || n < 1) {
        cout << "Impossible" << endl;
        return 0;
    }

    int minimum = 5;
    // try all combinations
    for(int i = 0; i < (1<<n); i++) {
        memset(feasible, 0, sizeof(bool)*4);
        c = 0;

        //  1<<j shifts the 1 for j places and then we check j-th binary digit of i
        for(int j = 0; j < n; j++) if(i&(1<<j)) { // if using this crane
            c++;
            for(int g=0; g<4; g++) feasible[g] |= reach[j][g];
            if(c == 4) break;
        }

        if(!feasible[0] || !feasible[1] || !feasible[2] || !feasible[3]) continue;

        minimum = min(minimum, c);
        if(minimum == 2) break;
        if(minimum == 3) break;
        if(minimum == 4) break;
    }

    cout << minimum << endl;

    return 0;
}
