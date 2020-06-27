#include <iostream>

using namespace std;

int main() {
    char c;
    while(cin >> c) {
        if(c > 64 && c < 91) cout << c;
    }
    cout << endl;
}
