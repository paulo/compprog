#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, string> m = {
    {1,"one"},
    {2,"two"},
    {3,"three"},
    {4,"four"},
    {5,"five"},
    {6,"six"},
    {7,"seven"},
    {8,"eight"},
    {9,"nine"},
    {10,"ten"},
    {11,"eleven"},
    {12,"twelve"},
    {13,"thirteen"},
    {14,"fourteen"},
    {15,"fifteen"},
    {16,"sixteen"},
    {17,"seventeen"},
    {18,"eighteen"},
    {19,"nineteen"},
    {20,"twenty"},
    {30,"thirty"},
    {40,"forty"},
    {50,"fifty"},
    {60,"sixty"},
    {70,"seventy"},
    {80,"eighty"},
    {90,"ninety"},
    {100, "hundred"}
};

typedef long long ll;

int main() {
    ll total = 0;

    for(int i = 1; i <= 20; i++) {
        total += m[i].length();
    }

    for(int i = 21; i < 1000; i++) {
        if(i / 100 == 0) { // tens
            if(m.find(i) != m.end()) total += m[i].length();
            else {
                total += m[i%10].length();
                total += m[i - (i%10)].length();
            }
        } else { // hundreds
            total += 7; // "hundred"

            total += m[i / 100].length(); // how many hundreds

            if(i % 100 == 0) continue; // if not round number

            total += 3; // and

            if(m.find(i%100) != m.end()) { // if special case
                total += m[i%100].length();
            } else {
                total += m[i%10].length(); // units
                total += m[i - ((i/100) * 100) - i % 10].length(); // tens
            }
        }
    }

    total += 11; // one thousand
    cout << total << endl;
}
