#include <iostream>

using namespace std;

int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leapYear(int year) {
    if(year % 100 == 0) return year % 400 == 0;

    return year % 4 == 0;
}

// Very naive implementation, but I'm doing this before sleep so...
int main() {

    int currMonth = 1, currMonthDays, currDay = 1, currYear=1900, weekDay=1, total = 0; // monday

    while(currYear != 2000 || currMonth != 12 || currDay != 31) {
        currDay++; weekDay++;
        currMonthDays = monthDays[currMonth-1];
        if(currMonth == 2 && leapYear(currYear)) currMonthDays++;

        if(currDay > currMonthDays) {
            currDay = 1;
            currMonth++;

            if(currMonth > 12) {
                currMonth = 1;
                currYear++;
            }
        }

        if(weekDay > 7) weekDay = 1;
        if(currYear > 1900 && weekDay == 7 && currDay == 1) total++;
    }

    cout << total << endl;
}
