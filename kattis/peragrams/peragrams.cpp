#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string s;
    cin >> s;
    int m[30];
    memset(m, 0, 30*sizeof(int));

    if(s.length() == 1) {
        cout << 0 << endl;
        return 0;
    }

    for(int i=0; i < s.length(); i++) m[s[i]-97]++;

    int c = 0;
    for(int i=0; i < 30; i++){
        if(m[i] % 2 != 0) {
            c++;
        }
    }

    if(c==0) cout << 0 << endl;
    else cout << c-1 << endl;
    return 0;
}
