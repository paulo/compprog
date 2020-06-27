#include <iostream>

using namespace std;

int main() {
    int n, spd, t;

    while(cin >> n && n!=-1){
        int tim=0, dist=0;
        for(int i=0; i<n; i++){
            cin >> spd >> t;
            dist += (spd * (t-tim));
            tim=t;
        }

        cout << dist << " miles" << endl;
    }
}
