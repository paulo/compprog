#include <iostream>

using namespace std;

typedef long long ll;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* _next) : val(x), next(_next) {}
};

// Traverse all nodes keeping track of the last odd node. Insert always after
// that node the odd ones encountered.
class Solution {
   public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *lastOdd = head, *curr = head->next, *prev = head,
                 *next = NULL;
        bool odd = false;

        while (curr) {
            next = curr->next;
            if (odd) {
                prev->next = curr->next;
                curr->next = lastOdd->next;
                lastOdd->next = curr;
                lastOdd = curr;
            }

            prev = curr;
            curr = next;
            odd = !odd;
        }

        return head;
    }
};

int main() {
    ListNode l11111 = ListNode(5, NULL);
    ListNode l1111 = ListNode(4, &l11111);
    ListNode l111 = ListNode(3, &l1111);
    ListNode l11 = ListNode(2, &l111);
    ListNode l1 = ListNode(1, &l11);

    ListNode* r = Solution().oddEvenList(&l1);

    while (r) {
        cout << r->val << ' ';
        r = r->next;
    }
    cout << endl;

    return 0;
}
