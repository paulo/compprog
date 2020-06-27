#include <iostream>
#include <string.h>

using namespace std;

typedef long double ld;

int main() {
    cout.precision(17);
    for(int i = 2; i < 10; i++) {
        ld aux = 1/ld(i);
        string s = to_string(aux);
        cout << s << endl;
    }

    return 0;
}
