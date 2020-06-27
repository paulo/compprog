#include <iostream>
#include <vector>

using namespace std;

typedef pair<char, pair<char,char>> op;

int main() {
    string s;

    while(cin >> s && s != "0"){
        vector<op> ops;
        cout << s << endl;

        char w, x;
        for(int i = s.length()-1; i >= 0; i--){
            switch(s[i]) {
                case 'K': // and
                    w = s[i+1]; x = s[i+2];
                    if(x < 97) {
                        x = '.';
                        i++;
                    } else i+=2;
                    ops.push_back(op(s[i], make_pair(w, x)));

                    break;
                case 'A': // or
                    break;
                case 'N': // not
                    break;
                case 'C': // implies
                    break;
                case 'E': // equals
                    break;
                default:

                    break;
            }
        }
    }

    return 0;
}
