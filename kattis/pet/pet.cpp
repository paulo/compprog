#include <iostream>

using namespace std;

int main() {
    int maxrow=0, maxtotal=0, aux;

    for(int i = 0; i < 5; i++) {
        int total = 0;
        for(int j = 0; j < 4; j++) {
            cin >> aux;
            total+=aux;
        }

        if (total > maxtotal) {
            maxrow = i+1;
            maxtotal = total;
        }
    }

    cout << maxrow << ' ' << maxtotal << endl;

    return 0;
}
