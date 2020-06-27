#include <iostream>

using namespace std;

int main() {
    char aux;
    char s[10000000];

    int i=0;
    while(cin >> aux) {
        if(aux == '<') i--;
        else s[i++] = aux;
    }

    if(i == 0) return 0;

    for(int k=0; k<i; k++) cout << s[k];
    cout << endl;
}
