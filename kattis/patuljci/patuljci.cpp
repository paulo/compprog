#include <iostream>
#include <vector>

using namespace std;

// traverse combinations that include 7 dwarves and whose sum is equal to 100
int main() {
    vector<int> m(9);
    for(int i = 0; i < 9; i++) cin >> m[i];

    for(int i=0; i < (1<<9)-1; i++) {
        int sum = 0, total = 0;
        for(int k = 0; k < 9; k++) if(i&(1<<k)) {sum+=m[k]; total++;}

        if(sum == 100 && total == 7) {
            for(int k = 0; k < 9; k++) if(i&(1<<k)) cout << m[k] << endl;
            break;
        }
    }
}
