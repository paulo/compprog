#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution also works for the armystrengthhard problem
int main() {
    int t;
    cin >> t;

    int ng, nm, ii, jj;
    for (int i = 0; i < t; i++) {
        ii = 0;
        jj = 0;

        cin >> ng >> nm;

        vector<int> vg(ng);
        vector<int> vm(nm);
        for (int j = 0; j < ng; j++) cin >> vg[j];
        for (int j = 0; j < nm; j++) cin >> vm[j];

        sort(vg.begin(), vg.end());
        sort(vm.begin(), vm.end());

        while (ii < ng && jj < nm) {
            if (vg[ii] >= vm[jj]) {
                jj++;
            } else {
                ii++;
            }
        }

        if (ii == ng) {
            cout << "MechaGodzilla" << endl;
        } else {
            cout << "Godzilla" << endl;
        }
    }

    return 0;
}
