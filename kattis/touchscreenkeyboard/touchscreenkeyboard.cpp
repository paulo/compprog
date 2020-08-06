#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<char, pair<int, int>> keeb = {
    {'q',make_pair(0, 0)},
    {'w',make_pair(0, 1)},
    {'e',make_pair(0, 2)},
    {'r',make_pair(0, 3)},
    {'t',make_pair(0, 4)},
    {'y',make_pair(0, 5)},
    {'u',make_pair(0, 6)},
    {'i',make_pair(0, 7)},
    {'o',make_pair(0, 8)},
    {'p',make_pair(0, 9)},
    {'a',make_pair(1, 0)},
    {'s',make_pair(1, 1)},
    {'d',make_pair(1, 2)},
    {'f',make_pair(1, 3)},
    {'g',make_pair(1, 4)},
    {'h',make_pair(1, 5)},
    {'j',make_pair(1, 6)},
    {'k',make_pair(1, 7)},
    {'l',make_pair(1, 8)},
    {'z',make_pair(2, 0)},
    {'x',make_pair(2, 1)},
    {'c',make_pair(2, 2)},
    {'v',make_pair(2, 3)},
    {'b',make_pair(2, 4)},
    {'n',make_pair(2, 5)},
    {'m',make_pair(2, 6)},
};

int main() {
    int t;
    cin >> t;

    string s, aux;
    int n, dist = 0;

    for(int i = 0; i < t; i++){
        cin >> s >> n;

        vector<pair<int, string>> v;
        for(int j = 0; j < n; j++){
            cin >> aux;

            dist = 0;
            for(int k = 0; k < aux.length(); k++){
                dist += abs(keeb[aux[k]].first - keeb[s[k]].first);
                dist += abs(keeb[aux[k]].second - keeb[s[k]].second);
            }

            v.push_back(make_pair(dist, aux));
        }

        sort(v.begin(), v.end());

        for(auto x : v) cout << x.second << ' ' << x.first << endl;
    }

    return 0;
}
