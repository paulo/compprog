#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    char s;
    cin >> s;

    unordered_map<char, pair<int, int>> v = {
        {'A',make_pair(11, 11)},
        {'K',make_pair(4, 4)},
        {'Q',make_pair(3, 3)},
        {'J',make_pair(20, 2)},
        {'T',make_pair(10, 10)},
        {'9',make_pair(14, 0)},
    };

    int t = 0;
    char a, b;
    for(int i = 0; i < n*4; i++) {
        cin >> a >> b;

        if(v.find(a) == v.end()) continue;
        if(b == s) t += v[a].first;
        else t += v[a].second;
    }

    cout << t << endl;
    return 0;
}
