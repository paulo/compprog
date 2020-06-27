#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

map<string, long> global;
queue<map<string, long>> q;

struct pair_compare {
    bool operator() (const pair<string,int>& p1, const pair<string,int>& p2) const {
        if(p1.second != p2.second) return p1.second > p2.second;

        return p1.first < p2.first;
    }
};

int main() {
    string s;

    map<string, long> daily;
    int t;
    set<pair<string, long>, pair_compare> res;
    while(cin >> s) {
        if(s == "<text>") {
            while(cin >> s && s != "</text>"){
                if(s.length() > 3) daily[s]++;
            }
            if(s == "</text>") {
                if(q.size() == 7) {
                    for(auto w:q.front()) global[w.first] -= w.second;
                    q.pop();
                }
                for(auto w:daily) global[w.first] += w.second;
                q.emplace(daily);
                daily.clear();
            }
        } else if(s == "<top") {
            cin >> t;
            cin >> s; // consume '/>'
            for(auto w:global) {
                if(w.second > 0) res.insert(make_pair(w.first,w.second));
            }
            cout << "<top " << t << '>' << endl;
            int lastc = -2;
            for(auto p:res) {
                if(t > 0 || (t <= 0 && p.second == lastc)){
                    lastc = p.second;
                    cout << p.first << ' ' << p.second << endl;
                } else break;
                t--;
            }
            cout << "</top>" << endl;

            res.clear();
            continue;
        }
    }

    return 0;
}
