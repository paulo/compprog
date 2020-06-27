#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, int> trim;
    // precalc triangle numbers
    for(int i = 0; i < 1000; i++) trim[(i * (i+1)/2)] = i;

    string s;
    int total = 0;
    while(cin >> s) {
        int value = 0;
        for(int i = 0; i < s.length(); i++) value += s[i] - 96;
        if(trim.find(value) != trim.end()) total++;
    }

    cout << total << endl;
}
