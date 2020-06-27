#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <stdlib.h>

using namespace std;

template <class Container>
void split(const std::string& str, Container& cont, char delim = ' ');
string calc(map<string, int> wordToNum, map<int, string> numToWord, vector<string> tokens);

int main() {
    map<string, int> wordToNum;
    map<int, string> numToWord;
    vector<string> tokens;

    // Read lines from stdin
    for (string line; getline(cin, line);) {
        split(line, tokens);

        string cmd = tokens.front();
        if (cmd == "clear") {
            wordToNum.clear();
            numToWord.clear();
        } else if (cmd == "def") {
            string word = tokens[1];
            string rawNum = tokens[2];
            int num = stoi(rawNum);

            //If x had been defined previously, defining it again erases its old definition.
            if (wordToNum.find(word) != wordToNum.end()) {
                numToWord.erase(wordToNum[word]);
            }

            wordToNum[word] = num;
            numToWord[num] = word;
        } else if (cmd == "calc") {
            string res;
            for(int i = 1; i < tokens.size(); i++) {
                cout << tokens[i] << ' ';
            }

            cout << calc(wordToNum, numToWord, tokens) << endl;
        }

        tokens.clear();
    }

    return 0;
}

string calc(map<string, int> wordToNum, map<int, string> numToWord, vector<string> tokens) {
    int currentCalc = 0;
    string prevToken;
    bool sum;

    for(int i = 1; i < tokens.size(); i++){
        string token = tokens[i];

        if (token == "+") {
            sum = true;
        } else if (token == "-") {
            sum = false;
        } else if (token == "=") {
            // Result does not exist
            if (numToWord.find(currentCalc) == numToWord.end()) {
                break;
            }

            return numToWord[currentCalc];
        } else { //Word
            if (wordToNum.find(token) == wordToNum.end()) {
                break;
            }

            if(prevToken.empty() || sum) {
                currentCalc += wordToNum[token];
            } else {
                currentCalc -= wordToNum[token];
            }

            prevToken = token;
        }
    }

    return "unknown";
}

template <class Container>
void split(const string& str, Container& cont, char delim){
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        cont.push_back(token);
    }
}
