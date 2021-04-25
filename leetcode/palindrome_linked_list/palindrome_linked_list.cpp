#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    bool isPalindrome(ListNode *head) {
        ListNode *mid = head, *aux = head, *prev = NULL;

        bool go = false;
        while (aux) {
            aux = aux->next;
            if (go) mid = mid->next;

            go = !go;
        }

        // invert from the middle forward
        while (mid) {
            aux = mid;
            mid = mid->next;
            aux->next = prev;
            prev = aux;
        }

        while (prev) {
            if (prev->val == head->val) {
                prev = prev->next;
                head = head->next;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    ListNode l11111 = ListNode(1, NULL);
    ListNode l1111 = ListNode(2, &l11111);
    ListNode l111 = ListNode(2, &l1111);
    ListNode l11 = ListNode(1, &l111);

    cout << Solution().isPalindrome(&l11);

    return 0;
}
