#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, y;
    cin >> n;

    unordered_map<string, vector<int>> msi;

    string c;
    for(int i = 0; i < n; i++) {
        cin >> c >> y;
        if(msi.find(c) == msi.end()){
            msi[c] = vector<int>();
        }
        msi[c].push_back(y);
    }

    for(auto x:msi) {
        vector<int> vi = x.second;
        sort(vi.begin(), vi.end());
        msi[x.first] = vi;
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> c >> y;

        cout << msi[c][y-1] << endl;
    }
}
