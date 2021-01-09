#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        ListNode *prev = NULL, *next = NULL, *curr = head;

        while (curr) {
            if (prev && curr == head) {
                return true;
            }
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return false;
    }
};

int main() {
    ListNode *l1 = new ListNode(3);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(0);
    ListNode *l4 = new ListNode(-4);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l2;

    cout << Solution().hasCycle(l1) << endl;

    return 0;
}
