#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> vi(50);
    int ni, ti;
    for(int i = 0; i < n; i++) {
        cin >> ni >> ti;

        for(int j=ti; j>=0 && ni > 0; j--) {
            int nj = vi[j];
            vi[j] = max(ni,nj);
            ni = min(ni,nj);
        }
    }

    int total = 0;
    for(int i = 0; i <= t; i++) total += vi[i];

    cout << total << endl;

    return 0;
}
