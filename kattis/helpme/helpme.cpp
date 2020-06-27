#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char pieces[] = {'K', 'Q', 'R', 'B', 'N', 'P'};

struct pair_compare_white {
    bool operator() (const pair<char,pair<int, int>>& p1, const pair<char,pair<int,int>>& p2) const {
        char *e1, *e2;

        e1 = find(pieces, pieces+6, p1.first);
        e2 = find(pieces, pieces+6, p2.first);

        if(distance(pieces, e1) != distance(pieces, e2))
            return distance(pieces, e1) < distance(pieces, e2);

        if(p1.second.first != p2.second.first) // different row
            return p1.second.first < p2.second.first;

        if(p1.second.second != p2.second.second) // different column
            return p1.second.second < p2.second.second;

        return false;
    }
};

struct pair_compare_black {
    bool operator() (const pair<char,pair<int, int>>& p1, const pair<char,pair<int,int>>& p2) const {
        char *e1, *e2;

        e1 = find(pieces, pieces+6, p1.first);
        e2 = find(pieces, pieces+6, p2.first);

        if(distance(pieces, e1) != distance(pieces, e2))
            return distance(pieces, e1) < distance(pieces, e2);

        if(p1.second.first != p2.second.first) // different row
            return p1.second.first > p2.second.first;

        if(p1.second.second != p2.second.second) // different column
            return p1.second.second < p2.second.second;

        return false;
    }
};


int main() {
    vector<pair<char, pair<int, int>>> whitep, blackp; // pieces and position

    string s, delimiter = "|", token;
    int i = 0, j=0;
    getline(cin, s);

    pair<int, int> p;
    char c;
    while(getline(cin, s)){
        s = s.substr(1, s.length()-1); // remove first delimiter
        size_t pos = 0;
        j=0;
        while ((pos = s.find(delimiter)) != string::npos) {
            token = s.substr(0, pos);
            c = toupper(token[1]);
            p = make_pair(8-i, j);

            if(token[1] >= 65 && token[1] <= 90) {
                whitep.push_back(make_pair(c, p));
            } else if(token[1] >= 97 && token[1] <= 122) {
                blackp.push_back(make_pair(c, p));
            }

            j++;
            s.erase(0, pos + delimiter.length());
        }

        getline(cin, s); // consume separating line
        i++;
    }

    sort(whitep.begin(), whitep.end(), pair_compare_white());
    sort(blackp.begin(), blackp.end(), pair_compare_black());

    cout << "White: ";
    for(int i = 0; i < whitep.size(); i++) {
        auto x = whitep[i];
        if(x.first != 'P') cout << x.first;
        char c = x.second.second + 97;
        cout << c << x.second.first;

        if(i != whitep.size() - 1) cout << ',';
    }

    cout << endl << "Black: ";
    for(int i = 0; i < blackp.size(); i++) {
        auto x = blackp[i];
        if(x.first != 'P') cout << x.first;
        char c = x.second.second + 97;
        cout << c << x.second.first;

        if(i != blackp.size() - 1) cout << ',';
    }
    return 0;
}
