#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pair_compare_greater {
    bool operator() (const pair<int,int>& p1, const pair<int,int>& p2) const {
        return p1.second > p2.second || p1.first < p2.first;
    }
};

struct pair_compare_lower {
    bool operator() (const pair<int,int>& p1, const pair<int,int>& p2) const {
        return p1.second < p2.second || p1.first > p2.first;
    }
};


// Solve greedly
int main() {
    int n, aux;
    cin >> n;
    vector<pair<int, int>> vn(n);

    for(int i = 0; i < n; i++) {
        cin >> aux;
        vn[i] = make_pair(i, aux);
    }

    // Optimum solution for teacher 1
    sort(vn.begin(), vn.end(), pair_compare_greater());
    vector<int> t1;
    for(int i = 0; i < n; i++) { // Fill teacher 1 timetable
        for(int j = 0; j < vn[i].second; j++) t1.push_back(vn[i].first);
    }

    // Optimum solution for teacher 2
    sort(vn.begin(), vn.end(), pair_compare_lower());
    vector<int> t2;
    for(int i = 0; i < n; i++) { // Fill teacher 1 timetable
        for(int j = 0; j < vn[i].second; j++) t2.push_back(vn[i].first);
    }

    for(int i=0; i < t1.size(); i++) cout << t1[i] << ' ';
    cout << endl;

    for(int i=0; i < t2.size(); i++) cout << t2[i] << ' ';
    cout << endl;

    // Adjust with gaps if needed (I know, it's not efficient but it's intuitive)
    int i = 0, j = 0;
    while(i < t1.size()) {
        if(t1[i] == t2[j]) {
            t2.insert(t2.begin() + j, -1);
        } else {
            i++;
            j++;
        }
    }

    cout << t2.size() << endl;
}
