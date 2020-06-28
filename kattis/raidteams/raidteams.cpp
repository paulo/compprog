#include <iostream>
#include <map>
#include <set>
#include <vector>

typedef long long ll;

using namespace std;

struct pair_compare {
    bool operator() (const pair<string,ll>& p1, const pair<string,ll>& p2) const {
        if(p1.second == p2.second) return p1.first < p2.first;

        return p1.second > p2.second;
    }
};

int main() {
    int n;
    cin >> n;

    string s;
    ll s1, s2, s3;

    map<string, vector<ll>> m;

    // Take advantage of the BST underneath to order the results
    set<pair<string, ll>, pair_compare> m1;
    set<pair<string, ll>, pair_compare> m2;
    set<pair<string, ll>, pair_compare> m3;

    for(int i = 0; i < n; i++) {
        cin >> s >> s1 >> s2 >> s3;
        m[s] = vector<ll>{s1, s2, s3};
        m1.insert(make_pair(s, s1));
        m2.insert(make_pair(s, s2));
        m3.insert(make_pair(s, s3));
    }

    while(!m1.empty()) {
        auto r1 = m1.begin();

        // erase chosen from memory
        auto r12it = m2.find(make_pair(r1->first, m[r1->first][1]));
        auto r13it = m3.find(make_pair(r1->first, m[r1->first][2]));
        m1.erase(r1);
        m2.erase(r12it);
        m3.erase(r13it);

        if(m2.empty() || m3.empty()) break;

        auto r2 = m2.begin();

        auto r21it = m1.find(make_pair(r2->first, m[r2->first][0]));
        auto r23it = m3.find(make_pair(r2->first, m[r2->first][2]));
        m1.erase(r21it);
        m2.erase(r2);
        m3.erase(r23it);

        if(m3.empty()) break;

        auto r3 = m3.begin();

        auto r31it = m1.find(make_pair(r3->first, m[r3->first][0]));
        auto r32it = m2.find(make_pair(r3->first, m[r3->first][1]));
        m1.erase(r31it);
        m2.erase(r32it);
        m3.erase(r3);

        if (r1->first > r3->first) swap(r1, r3);
        if (r1->first > r2->first) swap(r1, r2);
        if (r2->first > r3->first) swap(r2, r3);

        cout << r1->first << " " << r2->first << " " << r3->first << endl;
    }

    return 0;
}
