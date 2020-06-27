#include <iostream>
#include <map>

using namespace std;

int main() {
    int nFiles, col;

    string nline, line;
    map<char,int> mci;
    map<string, int> msi;
    while(getline(cin, nline)) {
        if(nline == "0") break;
        nFiles = stoi(nline);

        mci.clear();
        msi.clear();
        col=0;
        for(int i=0; i<nFiles; i++) {
            getline(cin, line);

            char xored = 0;
            for (char const &c: line) xored = xored == '\0' ? c : xored ^ c;

            // The collisions are the difference between the amount of equal hashes for a given line
            // and the amount of times that line has appeared. If a given line appears twice (same hash as well)
            // the collision would be 0. If 3 different lines appear once (with 1 hash), the collision is 2.
            col += ++mci[xored] - ++msi[line];
        }
        cout << msi.size() << ' ' << col << endl;
    }

    return 0;
}
