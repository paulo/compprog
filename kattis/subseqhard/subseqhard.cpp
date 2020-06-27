#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

// Given a sequence, find the count of its subsequences whose sum is 47.
int main() {
    int tcases;
    cin >> tcases;

    for(int i=0; i<tcases;i++){
        int n;
        cin >> n;

        // if mii contains an element which is the result of the different between sum(0, v[j]) and 47,
        // that means that there's a sum over a range of those numbers which equals 47. If that number
        // appears multiple times in mii, it means there's multiple ranges that provide 47
        int it=0, aux;
        double sum = 0;
        map<double, int> mdi;

        for(int j=0; j<n; j++) {
            cin >> aux;
            mdi[sum]++;
            sum+= aux;
            if(mdi[sum - 47] != 0) it+= mdi[sum-47];
        }

        cout << it << endl;
    }

    return 0;
}
