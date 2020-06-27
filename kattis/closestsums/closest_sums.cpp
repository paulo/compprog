#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int cases(set<int> nums, int query);

int main() {
    int numC = 0; // total amount of cases
    int numQ; // current number of queries
    int numI; // current number of numbers
    set<int> nums; // current numbers

    int aux;
    while (cin >> numI){
        cout << "Case " << ++numC << ':' << endl;

        for(int i = 0; i< numI; i++){
            cin >> aux;
            nums.insert(aux); // This is ordered
        }

        cin >> numQ; // get number of queries

        for(int i = 0; i < numQ; i++){
            cin >> aux;
            cout << "Closest sum to " << aux << " is " << cases(nums, aux) << "." << endl;
        }

        nums.clear();
    }

    return 0;
}

int cases(set<int> nums, int query) {
    int diff = query;
    int closest = 0;

    set <int> :: iterator itr;
    set <int> :: iterator itr2;
    int sum, auxDiff;
    for (itr = nums.begin(); itr != prev(nums.end(), 1); itr++){
        for(itr2 = next(itr, 1); itr2 != nums.end(); itr2++) {
            sum = *itr + *itr2;

            if (sum == query) {
                return sum;
            }

            auxDiff = abs(sum-query);
            if (diff > auxDiff || closest == 0) {
                diff = auxDiff;
                closest = sum;
            }
        }
    }

    return closest;
}
