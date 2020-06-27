#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int r, c, zr, zc;
    char nm[500][500], aux;
    memset(nm, 0, 500*500*sizeof(char));

    cin >> r >> c >> zr >> zc;

    int ci=0, cj=0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> aux;
            for(int zi=0; zi < zr; zi++){
                for(int zj=0; zj < zc; zj++){
                    nm[ci+zi][cj+zj] = aux;
                }
            }
            cj += zc;
        }
        cj = 0;
        ci += zr;
    }

    for(int i = 0; i < r*zr; i++){
        for(int j = 0; j < c*zc; j++){
            cout << nm[i][j];
        }
        cout << endl;
    }

    return 0;
}
