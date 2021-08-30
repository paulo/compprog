#include <bits/stdc++.h>

using namespace std;

const string eof = "***END***";

int main() {
    int n;
    string aux, filename;
    getline(cin, aux);
    n = stoi(aux);

    unordered_map<string, vector<string>> m;
    auto r = std::regex("^ +| +$|( ) +");

    unordered_map<string, unordered_map<string, bool>> ltf;  // line to file

    for (int i = 0; i < n; i++) {
        getline(cin, filename);  // filename
        m[to_string(i) + "|" + filename] =
            vector<string>();  // guarantee unique filenames

        while (getline(cin, aux)) {
            aux = regex_replace(aux, r, "$1");
            if (aux.length() == 0) continue;
            if (aux == eof) break;

            m[filename].push_back(aux);
            ltf[aux][filename] = true;

            cout << aux << endl;
        }
    }

    vector<string> file;

    // The actual file
    while (getline(cin, aux)) {
        aux = regex_replace(aux, r, "$1");
        if (aux.length() == 0) continue;
        if (aux == eof) break;

        file.push_back(aux);

        cout << aux << endl;
    }

    // Compare files. This can be improved with more efficient comparison
    // algorithms

    return 0;
}
