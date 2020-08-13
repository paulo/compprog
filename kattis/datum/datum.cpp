#include <iostream>
#include <map>

using namespace std;

map<int, string> days = {
    {0, "Sunday"},
    {1, "Monday"},
    {2, "Tuesday"},
    {3, "Wednesday"},
    {4, "Thursday"},
    {5, "Friday"},
    {6, "Saturday"},
};

map<int, int> monthToDays = {
    {1, 31},
    {2, 28},
    {3, 31},
    {4, 30},
    {5, 31},
    {6, 30},
    {7, 31},
    {8, 31},
    {9, 30},
    {10, 31},
    {11, 30},
    {12, 31},
};

int main() {
    int d, m;
    cin >> d >> m;

    d+=3; // set it up to thursday with base 0
    for(int i=1; i<m; i++) d += monthToDays[i];

    cout << days[d % 7] << endl;

    return 0;
}
