#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Another solution: Instead of one pointer, we could use two pointers. The
// first pointer advances the list by n+1n+1 steps from the beginning, while the
// second pointer starts from the beginning of the list. The current  solution
// is hard on the stack, while this one can be done iteratively.
class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;

        return countAndRemove(head, n).first;
    }

    // counts how many nodes are after this one
    pair<ListNode*, int> countAndRemove(ListNode* curr, int n) {
        if (!curr) return make_pair(curr, 1);

        pair<ListNode*, int> t = countAndRemove(curr->next, n);
        curr->next = t.first;

        if (t.second == -1) return make_pair(curr, -1);
        if (t.second == n) return make_pair(curr->next, -1);

        return make_pair(curr, t.second + 1);
    }
};

int main() {
    ListNode l5 = ListNode(5, NULL);
    ListNode l4 = ListNode(4, &l5);
    ListNode l3 = ListNode(3, &l4);
    ListNode l2 = ListNode(2, &l3);
    ListNode l1 = ListNode(1, &l2);

    ListNode* r = Solution().removeNthFromEnd(&l1, 5);

    while (r) {
        cout << r->val << endl;
        r = r->next;
    }
    return 0;
}
