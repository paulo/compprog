#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* _next) : val(x), next(_next) {}
};

class Solution {
   public:
    void deleteNode(ListNode* node) {
        ListNode* prev;
        while (node->next) {
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }

        prev->next = NULL;
    }
};

int main() {
    ListNode* node =
        new ListNode(4, new ListNode(5, new ListNode(1, new ListNode(9))));

    Solution().deleteNode(node->next);

    while (node != NULL) {
        cout << node->val << endl;
        node = node->next;
    }

    return 0;
}
