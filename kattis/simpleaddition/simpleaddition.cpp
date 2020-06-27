#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXN=10100;

char i1[MAXN], i2[MAXN], i3[MAXN];

int main(){
    memset(i1, -1, MAXN);
    memset(i2, -1, MAXN);
    memset(i3, -1, MAXN);

    string line;
    getline(cin, line);
    istringstream iss(line);

    char aux;
    int i = MAXN-line.size()-1;
    int ii = i;
    while(iss >> aux) { i1[ii] = aux; ii++; }

    getline(cin, line);
    istringstream isss(line);

    int j = MAXN-line.size()-1;
    int jj = j;
    while(isss >> aux) { i2[jj] = aux; jj++; }

    int k = MAXN-1;
    i3[k] = '0';
    for(; k >= i || k >= j; k--) {
        aux = 0;
        if(i1[k] != -1) aux += i1[k] - 48;
        if(i2[k] != -1) aux += i2[k] - 48;

        i3[k] += aux;
        if(i3[k] > '9') {
            i3[k] = 48 + (i3[k] % 58);
            i3[k-1]='1';
        } else i3[k-1] = '0';
    }

    if(i3[k] == '0') k++;
    for(; k<MAXN-1; k++) cout << i3[k];
    cout << endl;
}
