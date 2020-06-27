#include <iostream>
#include <vector>

using namespace std;

    // 0 1 2 3 4 5 6 {3,4,8}
    // 2 1 3 4 7 5 6 8
//min/ 1 1 3 4 5 5 6 8
//max/ 2 2 3 4 7 7 7 8

// Track max from the left and min from the right
int main() {
    int n;
    cin >> n;

    vector<int> vi(n);
    // min, max vector
    vector<int> vmax(n);

    int max;
    cin >> vi[0];
    vmax[0] = max = vi[0];

    for(int i = 1; i < n; i++){
        cin >> vi[i];
        if(vi[i] > vmax[i-1]) max = vi[i];
        vmax[i] = max;
    }

    int min = vi[n-1];
    int total= 0;
    for(int i = n-1; i >= 0; i--) {
        if(vi[i] < min) min = vi[i];
        if(vmax[i] == min) total++;
    }

    cout << total << endl;
}
