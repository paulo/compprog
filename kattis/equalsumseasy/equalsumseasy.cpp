#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    int n;
    for(int i = 1; i <= t; i++) {
        cin >> n;

        vector<int> vi(n);
        map<int, vector<int>> mii;

        for(int j = 0; j < n; j++) cin >> vi[j];

        int sum = 0;
        for(int j = 0; j < (1<<n)-1; ++j) {
            sum=0;

            //  1<<k shifts the 1 for k places and then we check k-th binary digit of j
            for(int k = 0; k < n; k++) if(j&(1<<k)) sum+=vi[k];

            if(mii.find(sum) != mii.end()) {
                mii[sum].push_back(j);
                break;
            } else {
                mii[sum].push_back(j);
            }
        }

        cout << "Case #" << i << ':' << endl;

        if(sum==0) {
            cout << "Impossible" << endl;
        } else {
            for(auto x:mii[sum]){
                for(int k = 0; k < n; k++) {
                    if(x&(1<<k)) cout << vi[k] << ' ';
                }
                cout << endl;
            }
        }
    }

    return 0;
}
