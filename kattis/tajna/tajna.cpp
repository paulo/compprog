#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int l = s.length();
    int r = 1;
    for(int i=1; i <= l/2; i++) if(l % i == 0 && i <= l/i) r = i;

    int c = l/r;
    if(c > r) swap(c, r);

    for(int i=0; i < c; i++) for(int j=0; j < r; j++) cout << s[j*c+i];

    cout << endl;

    return 0;
}
