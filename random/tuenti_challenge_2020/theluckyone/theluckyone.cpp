#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int c, n, a, b;
    bool r;
    cin >> c;

    for(int i=1; i<=c; i++) {
        cin >> n;
        // Assuming each player appears at least once in a match
        // and that if si > sj and sj > sk then si > sk
        // the strongest player will be the one undefeated
        // The input size is quite small, so a vector<int> should do
        vector<bool> beats(n*2);

        for(int j=0; j<n; j++) {
            cin >> a >> b >> r;

            if(r) beats[b]=true;
            else beats[a]=true;
        }

        int m = min_element(beats.begin()+1,beats.end()) - beats.begin();
        cout << "Case #" << i << ": " << m << endl;
    }

    return 0;
}
