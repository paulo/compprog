#include <iostream>
#include <vector>

using namespace std;

class MinStack {
   public:
    vector<int> v;
    int index;
    int minElem;

    MinStack() {
        v = vector<int>(10000);
        index = 0;
        minElem = INT_MAX;
    }

    void push(int x) {
        if (x <= minElem) {
            v[index] = minElem;
            index++;
            minElem = x;
        }

        v[index] = x;
        index++;
    }

    void pop() {
        if (v[index - 1] == minElem) {
            index--;
            minElem = v[index - 1];
        }

        index--;
    }

    int top() { return v[index - 1]; }

    int getMin() { return minElem; }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(0);
    obj->push(1);
    obj->push(0);
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->getMin() << endl;

    return 0;
}
