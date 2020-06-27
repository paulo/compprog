#include <iostream>
#include <set>
#include <string>

using namespace std;

// ...1...6.
// 18...9...
// ..7.642..
// 2.9..6.5.
// .43...72.
// .6.3..9.1
// ..265.1..
// ...2...97
// .5...3...

int main() {
    int matrix[9][9];
    int emptyCells = 0;
    set<int> cells[9][9];

    char tmp;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> tmp;
            if(tmp == '.'){
                emptyCells++;
                matrix[i][j] = 0;
                cells[i][j].insert({1, 2, 3, 4, 5, 6, 7, 8, 9});
            } else {
                matrix[i][j] = atoi(&tmp);
            }
        }
    }

    bool lessEmptyCells = false;
    while(emptyCells > 0) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                
            }
        }

        if(!lessEmptyCells) {
            break;
        }
    }

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if (matrix[i][j] == 0) {
                cout << '.';
            } else {
                cout << matrix[i][j];
            }
        }
        cout << "\n";
    }

    return 0;
}
