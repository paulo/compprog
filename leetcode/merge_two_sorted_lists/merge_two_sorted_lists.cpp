#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL, *curr = NULL, *prev = NULL;

        while (l1 || l2) {
            if (l1 && l2 && l1->val < l2->val) {
                curr = l1;
                l1 = l1->next;
            } else if (l2) {
                curr = l2;
                l2 = l2->next;
            } else {
                curr = l1;
                l1 = l1->next;
            }

            if (!res) res = curr;
            if (prev) {
                prev->next = curr;
            }
            prev = curr;
        }

        return res;
    }
};

int main() {
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    ListNode* res = Solution().mergeTwoLists(l1, l2);

    while (res) {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}
