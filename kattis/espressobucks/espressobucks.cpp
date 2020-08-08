#include <iostream>
#include <stack>

using namespace std;

// - denotes a covered spot
int main() {
    int x, y;
    cin >> x >> y;

    stack<pair<int, int>> s;
    char m[110][110];

    for(int i = 0; i < x; i++) for(int j = 0; j < y; j++) cin >> m[i][j];

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if(m[i][j] == '#') continue;

            if(m[i][j] == '.') {
                s.push(make_pair(i, j));

                m[i][j] = 'E';

                if(i > 0 && m[i-1][j] != '#' && m[i-1][j] != 'E'){
                    m[i-1][j] = '-';
                }
                if(m[i+1][j] != '#' && m[i+1][j] != 'E') {
                    m[i+1][j] = '-';
                }
                if(j > 0 && m[i][j-1] != '#' && m[i][j-1] != 'E') {
                    m[i][j-1] = '-';
                }
                if(m[i][j+1] != '#'&& m[i][j+1] != 'E') {
                    m[i][j+1] = '-';
                }
            }
        }
    }

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if(m[i][j] == '-') cout << '.';
            else cout << m[i][j];
        }
        cout << endl;
    }


    return 0;
}
