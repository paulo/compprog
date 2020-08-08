#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int i, amount;
    float totalCalories = 0, totalFatCalories = 0;
    float fatPercentage = 0, fatCalories = 0, calories = 0, percentage = 0;

    char unit;
    bool slashed = false;
    string saux;
    while(getline(cin, saux)) {
        if(saux == "-") {
            if(slashed) break;
            slashed = true;

            cout << round((totalFatCalories / totalCalories) * 100) << '%' << endl;

            totalCalories = 0;
            totalFatCalories = 0;
        } else {
            slashed = false;
            i = 0;
            fatPercentage = 0;
            fatCalories = 0;
            calories = 0;
            percentage = 0;

            size_t pos = 0;
            string token;
            while ((pos = saux.find(' ')) != string::npos) {
                token = saux.substr(0, pos);
                saux.erase(0, pos + 1);
                unit = token[token.size()-1];
                amount = stoi(token.substr(0, token.size()-1));

                switch(unit) {
                    case 'g':
                        if(i == 0) {
                            calories += amount * 9;
                            fatCalories += amount * 9;
                        } else calories += amount * 4;
                        break;
                    case '%':
                        percentage += amount;
                        if(i == 0) fatPercentage = amount;
                        break;
                    case 'C':
                        calories += amount;
                        if(i == 0) fatCalories += amount;
                        break;
                }

                i++;
            }

            unit = saux[saux.size()-1];
            amount = stoi(saux.substr(0, saux.size()-1));

            switch(unit) {
                case 'g':
                    calories += amount * 7;
                    break;
                case '%':
                    percentage += amount;
                    break;
                case 'C':
                    calories += amount;
                    break;
            }

            if(fatPercentage != 0) {
                fatCalories = (calories * fatPercentage)/(100-percentage);
                totalFatCalories += fatCalories;
                totalCalories += (100 * fatCalories)/fatPercentage;
            } else {
                totalFatCalories += fatCalories;
                totalCalories += (100 * calories)/ (100 - percentage);
            }
        }
    }

    return 0;
}
