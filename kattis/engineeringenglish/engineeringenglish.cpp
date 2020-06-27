#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

int main() {
    string s, aux;

    unordered_map<string, bool> m;
    while(cin >> s) {
        aux = s;
        transform(aux.begin(), aux.end(), aux.begin(), asciitolower);
        if(m.find(aux) == m.end()) {
            m[aux] = true;
            cout << s << ' ';
        } else cout << '.' << ' ';
    }
}
