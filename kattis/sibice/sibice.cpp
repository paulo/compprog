#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n, w, h;
    cin >> n >> w >> h;

    float mx = sqrt(pow(w, 2) + pow(h, 2));

    float l;
    for(int i = 0; i < n; i++) {
        cin >> l;

        if(l <= mx) cout << "DA" << endl;
        else cout << "NE" << endl;
    }
}
