#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 2010;
int matrix[MAXN][MAXN];

int main() {
    int n, m;
    cin >> n >> m;

    memset(matrix, -1, MAXN*MAXN*sizeof(int));

    long long total=0;

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> matrix[i][j];

    // for(int i = 0; i < n; i++) {
        // for(int j = 0; j < m; j++) {
            // if(matrix[i][j] == 0) {
                // if(i==0 && j==0) {
                    // matrix[i][j] = 1;
                // } else if(i==0) {
                    // matrix[i][j] = matrix[i][j-1]+1;
                // } else if(j==0) {
                    // matrix[i][j] = matrix[i-1][j+1]+1;
                // } else if(j==m-1 && i==n-1) {
                    // matrix[i][j] = matrix[i][j-1]+1;
                // } else if(j==m-1) {
                    // matrix[i][j] = matrix[i-1][j]+1;
                    // // matrix[i][j] = max(matrix[i][j-1],matrix[i-1][j])+1;
                // } else if(i==n-1) {
                    // matrix[i][j] = matrix[i-1][j+1]+1;
                    // // matrix[i][j] = max(matrix[i][j-1],matrix[i-1][j])+1;
                // } else {
                    // matrix[i][j] = matrix[i-1][j+1]+1;
                // }
            // }

            // // if(corner.first != -1 && matrix[i][j] % 2 == matrix[corner.first][corner.second] % 2) matrix[i][j]++;

            // total += matrix[i][j];
        // }
    // }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            pair<int,int> corner = make_pair(-1, -1);

            if(matrix[i][j] == 0) {
                if(i==0 && j==0) {
                    matrix[i][j] = 1;
                } else if(i==0) {
                    // if(j==1) corner = make_pair(i+1,j-1);
                    // else if(j==m-2) corner = make_pair(i+1, j+1);

                    matrix[i][j] = matrix[i][j-1]+1;
                } else if(j==0) {
                    // if(i==1) corner = make_pair(i-1, j+1);
                    // if(i==n-2) corner = make_pair(i+1, j+1);

                    matrix[i][j] = matrix[i-1][j]+1;
                    if(matrix[i-1][j+1] == matrix[i][j]) matrix[i][j]++;
                } else if(j==m-1) {
                    // if(i==1) corner = make_pair(i-1, j-1);
                    // else if(i==n-2) corner = make_pair(i+1, j-1);

                    matrix[i][j] = max(matrix[i][j-1],matrix[i-1][j])+1;
                } else if(i==n-1) {
                    // if(j==1) corner = make_pair(i-1, j-1);
                    // else if(j==m-2) corner = make_pair(i-1, j+1);

                    matrix[i][j] = max(matrix[i][j-1],matrix[i-1][j])+1;
                } else {
                    matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1])+1;
                }
            }


            // look ahead
            int k=i+1, w=j+1;
            bool even = matrix[i][j] % 2 == 0;
            int tries = 0;
            while((k < n && w < m) && tries < 2){
                if(matrix[k][w] != 0 && (matrix[k][w] % 2 == 0) == even) {
                    matrix[i][j]++;
                    break;
                }

                even = !even;
                k++; w++; tries++;
            }

            if(corner.first != -1 && matrix[i][j] % 2 == matrix[corner.first][corner.second] % 2) matrix[i][j]++;

            total += matrix[i][j];
        }
    }

    bool valid = true;
    if(m>1) {
        for(int i = 0; i < n; i++) {
            int last = -1;
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] <= last) {
                    // cout << i << 'i' << j << endl;
                    valid = false;
                }
                else last = matrix[i][j];
            }
        }
    }

    if(n>1) {
        for(int j = 0; j < m; j++) {
            int last = -1;
            for(int i = 0; i < n; i++) {
                if(matrix[i][j] <= last) {
                    // cout << i << ' ' << j << endl;
                    valid = false;
                }
                else last = matrix[i][j];
            }
        }
    }

    if(m > 1 && n > 1) {
        if(matrix[0][1] % 2 == matrix[1][0] % 2) valid = false;
        if(matrix[n-1][1] % 2 == matrix[n-2][0] % 2) valid = false;
        if(matrix[n-2][m-1] % 2 == matrix[n-1][m-2] % 2) valid = false;
        if(matrix[0][n-2] % 2 == matrix[1][n-1] % 2) valid = false;
    }

    if(!valid) {
        cout << -1 << endl;
        return 0;
    }

    // for(int i = 0; i < n; i++) {
        // for(int j = 0; j < m; j++) cout << matrix[i][j] << ' ';
        // cout << endl;
    // }

    // cout << "----------------"<< endl;
    cout << total << endl;

    return 0;
}

