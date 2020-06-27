#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        if(s == "P=NP") cout << "skipped" << endl;
        else {
            string delimiter = "+";
            string n1 = s.substr(0, s.find(delimiter)); // token is "scott"
            string n2 = s.substr(s.find(delimiter)+1, s.length()); // token is "scott"

            cout << stoi(n1) + stoi(n2) << endl;
        }
    }
}
