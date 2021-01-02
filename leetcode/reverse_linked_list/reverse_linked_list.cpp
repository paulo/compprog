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
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

int main() {
    ListNode* l = new ListNode(
        1, new ListNode(2, new ListNode(3, new ListNode(4, NULL))));

    ListNode* res = Solution().reverseList(l);

    while (res) {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}
