#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct pair_compare {
    bool operator() (const pair<double,double>& p1, const pair<double,double>& p2) const {
        if(p1.first != p2.first) return p1.first < p2.first;

        return p1.second > p2.second;
    }
};

int main() {
    double n, l, w, x, r;
    double auxi;

    while(cin >> n >> l >> w) {
        vector<pair<double, double>> vi;

        for(int i = 0; i < n; i++) {
            cin >> x >> r;

            if(r < w/2) continue; // remove useless points

            auxi = w/2 / r;
            auxi = asin(auxi);
            auxi = r * cos(auxi); // calculate adjancent value

            vi.push_back(make_pair(x-auxi, x+auxi));
        }

        // Sort by starting point
        sort(vi.begin(), vi.end(),pair_compare());

        double fi=0, auxf;
        int total = 0;
        for(int i = 0; i < vi.size() && fi < l; i++){
            auxf=fi;
            for(int j=i; j < vi.size() && vi[j].first <= fi; j++){
                if(auxf < vi[j].second) {
                    auxf = vi[j].second;
                    i=j;
                }
            }
            if(auxf != fi){
                fi=auxf;
                total++;
            }
        }

        if(fi<=l) cout << -1 << endl;
        else cout << total << endl;
    }

    return 0;
}
