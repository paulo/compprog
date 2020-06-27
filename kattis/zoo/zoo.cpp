#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

int main() {
    int i = 1;
    string n;

    while(getline(cin, n) && n != "0") {
        map<string, int> m;

        for(int k=0; k<stoi(n); k++) {
            string s;
            getline(cin, s);

            string token;
            size_t pos = 0;
            while ((pos = s.find(' ')) != string::npos) {
                token = s.substr(0, pos);
                s.erase(0, pos + 1);
            }
            transform(s.begin(), s.end(), s.begin(), asciitolower);
            m[s]++;
        }

        cout << "List " << i++ << ':' << endl;
        for(auto a:m) {
            cout << a.first << " | " << a.second << endl;
        }
        cout << endl;
    }
}
