#include <bits/stdc++.h>

using namespace std;

// The trick here is to move the element to be removed to the end of the list
// so there's no need to update all those indexes after removal. Neat
class RandomizedSet {
    unordered_map<int, int> mem;  // val to vector indexes
    vector<int> v;                // values

   public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        mem = unordered_map<int, int>();
        v = vector<int>();
        srand(time(NULL));
    }

    /** Inserts a value to the set. Returns true if the set did not already
     * contain the specified element. */
    bool insert(int val) {
        if (mem.find(val) != mem.end()) return false;

        mem[val] = v.size();
        v.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the
     * specified element. */
    bool remove(int val) {
        if (mem.find(val) == mem.end()) return false;

        int aux = v[v.size() - 1];
        swap(v[mem[val]], v[v.size() - 1]);
        v.pop_back();
        mem[aux] = mem[val];
        mem.erase(val);

        return true;
    }

    /** Get a random element from the set. */
    int getRandom() { return v[rand() % v.size()]; }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
