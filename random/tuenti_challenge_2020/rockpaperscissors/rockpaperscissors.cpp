#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    char p1,p2,res;
    for(int i=1; i<=n; i++) {
        cin >> p1 >> p2;
        switch(abs(p1-p2)) { // kek
            case 3: res = 'S'; break;
            case 2: res = 'P'; break;
            case 1: res = 'R'; break;
            case 0: res = '-'; break;
        }
        cout << "Case #" << i << ": " << res << endl;
    }

    return 0;
}
