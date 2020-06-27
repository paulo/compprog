#include <iostream>

using namespace std;

int main() {
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    bool flip = (n % 2 != 0);
    for(int i = 0; i < s1.length(); i++) {
        if((s1[i] == s2[i] && flip) || (s1[i] != s2[i] && !flip)) {
            cout << "Deletion failed" << endl;
            return 0;
        }
    }

    cout << "Deletion succeeded" << endl;
    return 0;
}
