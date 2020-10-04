#include <iostream>

using namespace std;

int main() {
    int mw, rw, rh;
    int cmw, cmh, crw, crh;

    while (cin >> mw && mw != 0) {
        cmw = 0;
        cmh = 0;
        crw = 0;
        crh = 0;
        while (cin >> rw >> rh && (rw != -1 && rh != -1)) {
            if (crw + rw > mw) {  // rectangle doesn't fit
                cmw = max(cmw, crw);
                crw = rw;
                cmh += crh;
                crh = rh;
            } else {  // rectangle fits
                crw += rw;
                crh = max(crh, rh);
            }
        }
        cmw = max(cmw, crw);
        cmh += crh;

        cout << cmw << " x " << cmh << endl;
    }

    return 0;
}
