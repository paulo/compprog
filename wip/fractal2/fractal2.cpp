#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define PI 3.14159265

double dist(pair<double, double> p1, pair<double, double> p2) {
    return sqrt(pow(p2.first-p1.first, 2) + pow(p2.second-p1.second, 2));
}

pair<double, double> travel(
        pair<double, double> sp,
        vector<pair<double, double>> vdd,
        vector<double> percents,
        vector<double> angles,
        int depth,
        double fraction,
        double ratio,
        double currentPerc,
        double currentAngle)
{
    cout << "Before. Depth: " << depth << " Percentage: " << currentPerc << " Point: " << sp.first << ' ' << sp.second << " Ratio: " << ratio << " Angle: " << currentAngle * PI / 180 << endl;
    int i = 0;
    while(i < vdd.size()){
        // cout << "Here: " << currentPerc + (percents[i+1] * ratio) << endl;
        if((currentPerc + (percents[i+1] * ratio)) > fraction) break;
        currentPerc += percents[i+1] * ratio;
        sp = make_pair(
                sp.first + (
                    vdd[i].first * cos(currentAngle) -
                    vdd[i].second * sin(currentAngle)
                    ) * ratio,
                sp.second + (
                    vdd[i].first * sin(currentAngle) +
                    vdd[i].second * cos(currentAngle)
                    ) * ratio
                );
        i++;
    }


    if(depth == 1) {
        double diff = fraction - currentPerc; // percentage that's left to travel
        cout << "DIFF: " << diff << endl;

        return make_pair(sp.first + vdd[i].first * diff * cos(currentAngle), sp.second + vdd[i].second * diff * sin(currentAngle));
    }
    // cout << "Before. Ratio: " << ratio << " I: " << i <<endl;
    ratio *= (percents[i+1]);
    // cout << "After. Ratio: " << ratio << " I: " << i <<endl << endl;

    // if(i>0) currentAngle += angles[i-1];
    // cout <<"aaangle:  " <<angles[i];
    cout << "After. Depth: " << depth << " Percentage: " << currentPerc << " Point: " << sp.first << ' ' << sp.second << " Ratio: " << ratio << " I: " << i << " Angle: " << currentAngle * PI / 180 <<endl << endl;
    return travel(sp, vdd, percents, angles, depth-1, fraction, ratio, currentPerc, currentAngle);
}

int main() {
    int c, n, d;
    double x, y, lastx, lasty, f, len;
    cin >> c;

    for(int i = 0; i < c; i++){
        cin >> n;

        vector<pair<double, double>> vpp(n); // points
        vector<pair<double, double>> vdd(n-1); // vectors
        vector<double> vds(n-1); // segment lengths
        len = 0;
        cin >> lastx >> lasty; // initial point
        vpp[0] = make_pair(lastx, lasty);

        // calculate vectors and lengths
        for(int j=0; j < n-1; j++){
            cin >> x >> y;

            vpp[j+1] = make_pair(x, y);
            vdd[j] = make_pair(x-lastx, y-lasty);
            vds[j] = dist(make_pair(lastx, lasty), make_pair(x, y));
            len += vds[j];

            lastx = x; lasty = y;
        }
        cin >> d >> f;

        vector<double> percents(n); // point progress percentage
        percents[0] = 0;
        for(int j=1; j < n; j++) percents[j] = (vds[j-1] / len);

        vector<double> angles(n-2); // angles between vectors
        for(int j=1; j < n-1; j++) {
            pair<double, double> v1 = vdd[j];
            pair<double, double> v2 = vdd[j-1];
            // double dotp = v1.first * v2.first + v1.second * v2.second;
            // double mag1 = sqrt(pow(v1.first, 2) + pow(v1.second, 2));
            // double mag2 = sqrt(pow(v2.first, 2) + pow(v2.second, 2));
            angles[j-1] = atan2(v2.second, v2.first) - atan2(v1.second, v1.first);
            // angles[j-1] = acos(dotp / (mag1 * mag2));
        }

        cout << "Angles: " << endl;
        for(int j=0; j<n-2; j++) cout << angles[j] * 180 / PI << endl;
        cout << endl;

        pair<double, double> res = travel(vpp[0], vdd, percents, angles, d, f, 1, 0, 0);

        cout << res.first << ' ' << res.second << endl;
    }
}
