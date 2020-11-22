#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int i = (s.length() - 2) * 2;

    cout << 'h';
    while (i-- > 0) cout << 'e';
    cout << 'y' << endl;

    return 0;
}
