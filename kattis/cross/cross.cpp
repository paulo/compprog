#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int N=9;

char matrix[9][9];
set<char> sc[9][9]; // tracks possible values for each housing
char vals[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void clearbox(int i, int j, char v) {
    // Clears row and column
    for(int k=0; k<N; k++) sc[i][k].erase(v);
    for(int k=0; k<N; k++) sc[k][j].erase(v);

    // Clear assigned housing
    sc[i][j].clear();

    // Clear 3x3 box
    int boxi = (i/3)*3, boxj = (j/3)*3;
    for(int k=0; k<3; k++) for(int l=0; l<3; l++) sc[boxi+k][boxj+l].erase(v);
}

// Only need to track two houses for each up/down and left/right, as if they can
// have the number we're testing, so do the ones in diagonal
bool canAssign(int i, int j, char v) {
    int boxi = (i/3)*3, boxj = (j/3)*3;
    int count = 0;

    for(int k=0; k<3; k++) for(int l=0; l<3; l++) if(sc[boxi+k][boxj+l].count(v) > 0) count++;

    return count == 1;
}

bool validate() {
    // Box current contents
    vector<map<char, int>> vci;
    for(int k=0; k<N; k++) vci.push_back(map<char, int>());

    // Row and column current contents
    vector<map<char, int>> vmcirow;
    for(int k=0; k<N; k++) vmcirow.push_back(map<char, int>());
    vector<map<char, int>> vmcicol;
    for(int k=0; k<N; k++) vmcicol.push_back(map<char, int>());

    // Box possible contents
    vector<set<char>> pvci;
    for(int k=0; k<N; k++) pvci.push_back(set<char>());


    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int box = (i/3)*3 + (j/3);

            if(matrix[i][j] == '.') {
                for(auto k:sc[i][j]) pvci[box].insert(k);
                continue;
            } else {
                vmcicol[j][matrix[i][j]]++;
                vmcirow[i][matrix[i][j]]++;
                pvci[box].insert(matrix[i][j]);
            }
            vci[box][matrix[i][j]]++;
            // Check if box does not have duplicate elements on the same box
            if(vci[box][matrix[i][j]] > 1) {
                return false;
            }
        }
    }

    // Check it is possible to fill all the housings in a box
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int box = (i/3)*3 + (j/3);
            if(pvci[box].size() != 9) return false;
        }
    }

    for(int k=0; k<N; k++) {
        // Check if box does not have duplicate elements on the same row
        for(auto v:vmcirow[k]) {
            if(v.second > 1) {
                return false;
            }
        }

        // Check if box does not have duplicate elements on the same column
        for(auto v:vmcicol[k]) {
            if(v.second > 1) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    // Init tracking values
    for(int i=0; i<N; i++)for(int j=0; j<N; j++) sc[i][j] = set<char> (begin(vals), end(vals));

    char v;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> v;
            if(v != '.') clearbox(i, j, v);
            matrix[i][j] = v;
        }
    }

    if(!validate()){
        cout << "ERROR" << endl;
        return 0;
    }

    bool changed = true;
    while(changed) {
        changed = false;

        // For each housing, let's see if we can fill the gap
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                for(auto v:sc[i][j]){
                    if(!canAssign(i, j, v)) continue;

                    // It means that the number is valid in this box
                    clearbox(i, j, v);
                    matrix[i][j] = v;
                    if(!validate()){
                        cout << "ERROR" << endl;
                        return 0;
                    }

                    changed = true;
                    break; // housing is full, no need to loop anymore
                }
            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) cout << matrix[i][j];
        cout << endl;
    }

    return 0;
}
