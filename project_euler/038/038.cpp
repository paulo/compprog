#include <iostream>

using namespace std;

bool pandigital(string n) {
    if(n.length() != 9) return false;

    bool pan = true;
    for(int i = 49; i < 58; i++) if (n.find(i) == string::npos) pan = false;

    return pan;
}

int main() {
    int res = 0;
    for(int i=1; i<1000000; i++) {
        string s = "";

        for(int j=1; j<10; j++){
            s+=to_string(i*j);
            if(s.length() < 9) continue;
            if(s.length() > 9) break;
            if(pandigital(s)) res = max(stoi(s), res);
        }
    }

    cout << res << endl;
}
