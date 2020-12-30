#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode *head = NULL, *curr = NULL, *tmp = NULL;
        int aux;
        while (l1 || l2 || carry) {
            aux = 0;
            if (l1) aux += l1->val;
            if (l2) aux += l2->val;
            aux += carry;

            if (aux > 9) {
                aux = aux % 10;
                carry = 1;
            } else {
                carry = 0;
            }

            tmp = new ListNode(aux, NULL);
            if (!curr) {
                curr = tmp;
            } else {
                curr->next = tmp;
                curr = curr->next;
            }

            if (!head) head = curr;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return head;
    }
};

int main() {
    Solution s = Solution();

    ListNode l11111 = ListNode(3, NULL);
    ListNode l1111 = ListNode(2, &l11111);
    ListNode l111 = ListNode(1, &l1111);
    ListNode l11 = ListNode(4, &l111);
    ListNode l1 = ListNode(2, &l11);

    ListNode l222 = ListNode(4, NULL);
    ListNode l22 = ListNode(6, &l222);
    ListNode l2 = ListNode(5, &l22);

    ListNode* res = s.addTwoNumbers(&l1, &l2);

    while (res) {
        cout << res->val << ' ';
        res = res->next;
    }

    return 0;
}
