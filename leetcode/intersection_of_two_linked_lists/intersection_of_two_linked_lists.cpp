#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *_next) : val(x), next(_next) {}
};

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;
        if (!pa || !pb) return NULL;

        bool brk = false;
        while (pa || pb) {
            if (pa == pb) return pa;
            if (pa->next) {
                pa = pa->next;
            } else if (brk) {
                return NULL;
            } else {
                pa = headB;
                brk = true;
            }

            if (pb->next) {
                pb = pb->next;
            } else {
                pb = headA;
            }
        }

        return NULL;
    }
};

int main() {
    // listA = [1,9,1,2,4], listB = [3,2,4]

    ListNode l11111 = ListNode(4);
    ListNode l1111 = ListNode(2, &l11111);
    ListNode l111 = ListNode(1, &l1111);
    ListNode l11 = ListNode(9, &l111);
    ListNode l1 = ListNode(1, &l11);

    ListNode l2 = ListNode(3, &l1111);

    Solution s = Solution();

    cout << s.getIntersectionNode(&l1, &l2)->val << endl;

    return 0;
}
