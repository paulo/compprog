#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Compare {
   public:
    bool operator()(ListNode* l1, ListNode* l2) { return l1->val > l2->val; }
};

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        ListNode *res = NULL, *head = NULL;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) pq.push(lists[i]);
        }

        while (!pq.empty()) {
            ListNode* aux = pq.top();
            pq.pop();

            if (res == NULL) {
                res = aux;
                head = res;
            } else {
                res->next = aux;
                res = res->next;
            }

            if (aux->next != NULL) {
                pq.push(aux->next);
            }
        }

        return head;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // [1,4,5],[1,3,4],[2,6]
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));

    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* res = Solution().mergeKLists(lists);

    while (res != NULL) {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}
