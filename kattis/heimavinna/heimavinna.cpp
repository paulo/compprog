#include <iostream>

using namespace std;

int main() {
    string s, token, token2;
    cin >> s;

    int total = 0;
    bool prev = false;

    size_t pos = 0, pos2 = 0;

    while ((pos = s.find(";")) != string::npos) {
        token = s.substr(0, pos);

        pos2 = 0;
        while ((pos2 = token.find("-")) != string::npos) {
            token2 = token.substr(0, pos2);
            prev = true;
            token.erase(0, pos2 + 1);
        }

        if (prev) {
            total += stoi(token) - stoi(token2) + 1;
        } else {
            total++;
        }

        s.erase(0, pos + 1);
        prev = false;
    }

    while ((pos = s.find("-")) != string::npos) {
        token = s.substr(0, pos);
        prev = true;
        s.erase(0, pos + 1);
    }

    if (prev) {
        total += stoi(s) - stoi(token) + 1;
    } else {
        total++;
    }

    cout << total << endl;

    return 0;
}
