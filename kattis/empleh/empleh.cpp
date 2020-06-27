#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int k = 2, i, j;

    char board[8][8], auxc;
    memset(board, 0, sizeof(board));

    string aux;
    bool white = true;
    while(k-- > 0) {
        getline(cin, aux);
        if(aux.length() < 8) {
            white = !white;
            continue;
        }
        aux = aux.substr(7, aux.size()-7);

        size_t pos = 0;
        string token, delimiter = ",";
        while ((pos = aux.find(delimiter)) != string::npos) {
            token = aux.substr(0, pos);
            if(token.length() == 3) {
                auxc = token[0];
                i = 8 - (token[2]-48);
                j = (token[1]-97);
            } else {
                auxc = 'P';
                i = 8 - (token[1]-48);
                j = (token[0]-97);
            }
            if(!white) auxc = tolower(auxc);
            board[i][j] = auxc;

            aux.erase(0, pos + delimiter.length());
        }
        token = aux;
        if(token.length() == 3) {
                auxc = token[0];
                i = 8 - (token[2]-48);
                j = (token[1]-97);
            } else {
                auxc = 'P';
                i = 8 - (token[1]-48);
                j = (token[0]-97);
            }
            if(!white) auxc = tolower(auxc);
            board[i][j] = auxc;

        white = !white;
    }

    string sep = "+---+---+---+---+---+---+---+---+";
    cout << sep << endl;
    white = true;
    for(int i = 0; i < 8; i++) {
        cout << '|';
        for(int j = 0; j < 8; j++) {
            if(white) cout << '.'; else cout << ':';
            if(board[i][j] == 0) {
                if(white) cout << '.'; else cout << ':';
            } else cout << board[i][j];
            if(white) cout << '.' << '|'; else cout << ':' << '|';

            white = !white;
        }
        white = !white;
        cout << endl << sep << endl;
    }

    return 0;
}
