#include <iostream>

using namespace std;

int main() {
    bool i[3] = {true, false, false};

    char aux;
    while (cin >> aux) {
        switch (aux) {
            case 'A':
                swap(i[0], i[1]);
                break;
            case 'B':
                swap(i[1], i[2]);
                break;
            case 'C':
                swap(i[0], i[2]);
                break;
        }
    }

    for (int x = 0; x < 3; x++) {
        if (i[x]) cout << x + 1 << endl;
    }

    return 0;
}
