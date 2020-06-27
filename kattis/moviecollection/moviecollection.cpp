#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAXM = 1000001;

int tree[MAXM];

void update(int n, int index, int val) {
    while (index < n) {
        tree[index] += val;
        index += index & (-index);
    }
}

int sum(int index){
    int sum = 0;

    while (index>0) {
        sum += tree[index];
        index -= index & (-index);
    }

    return sum;
}

int main() {
    int n;
    cin >> n;

    int m, r, l;
    for(int i = 0; i < n; i++) {
        memset(tree, 0, MAXM);

        cin >> m >> r;
        vector<int> coll(m+1);
        for(int k = 1; k <=m; k++) {
            update(MAXM, k, 1);
            coll[k] = m - k+ 1; // the list is reversed so it can grow with positive indexes
        }

        // for(int g=0; g<=m; g++) cout << coll[g] << ' ';
        // cout << endl;

        // We track the sum of the movies that are BELOW the current query (easier as we only have
        // to update two values). coll serves to track what's the index of a current movie on the tree
        int currI = m, total;
        for(int j = 0; j < r; j++) {
            total = 0;
            currI++;
            cin >> l;
            total = sum(coll[l]);

            update(MAXM, coll[l], -1);
            coll[l] = currI;
            update(MAXM, coll[l], 1);
            cout << m - total << ' ';
        }

        cout << endl;
    }
}
