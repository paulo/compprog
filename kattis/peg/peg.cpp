#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char m[7][7];
    memset(m, 0, sizeof(char)*7*7);
    int i=0, j=0;

    for(; i < 2; i++) for(j=2; j < 5; j++) cin >> m[i][j];
    for(; i < 5; i++) for(j=0; j < 7; j++) cin >> m[i][j];
    for(; i < 7; i++) for(j=2; j < 5; j++) cin >> m[i][j];

    int total = 0;
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) {
            if(m[i][j]=='.') {
                if(i > 1 && m[i-1][j]=='o' && m[i-2][j]=='o') total++;
                if(i < 6 && m[i+1][j]=='o' && m[i+2][j]=='o') total++;
                if(j > 1 && m[i][j-1]=='o' && m[i][j-2]=='o') total++;
                if(j < 6 && m[i][j+1]=='o' && m[i][j+2]=='o') total++;
            }
        }
    }

    cout << total << endl;

    return 0;
}
