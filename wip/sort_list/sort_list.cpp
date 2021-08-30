#include <bits/stdc++.h>

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
    // mergesort with linked list
    ListNode* sortList(ListNode* head) {
        ListNode *aux = head, *prev = NULL;

        int c = 0;
        // count number of elements and get last element
        while (aux != NULL) {
            c++;
            prev = aux;
            aux = aux->next;
        }

        return head;
    }

    void mergeSort(ListNode* from, ListNode* to, int l, int r) {
        if (l >= r) return;

        int m = (r - l) / 2;

        ListNode *newFrom = from, *newTo;
        while (newFrom != NULL && m >= 0) {
            newTo = newFrom;
            newFrom = newFrom->next;
            m--;
        }

        mergeSort(from, newTo, l, l + m);
        mergeSort(newFrom, to, r - m, r);
        merge(from, newFrom, m);
    }

    void merge(ListNode* from1, ListNode* from2, int m) {
        int m1 = 0, m2 = 0;
        ListNode *aux1 = from1, *aux2 = from2, *prev1 = NULL;

        while (m1 < m && m2 < m) {
            if (aux1->val > aux2->val) {
                prev1->next = aux2;
                aux2
                aux1->next = aux2->next;
                aux2->next = aux1;
            } else {
                prev1 = aux1->next;
                aux1 = aux1->next;
            }
            // prev1 = aux1;
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // -1,5,3,4,0
    ListNode* head = new ListNode(
        -1, new ListNode(
                5, new ListNode(3, new ListNode(4, new ListNode(0, NULL)))));

    ListNode* aux = head;
    while (aux != NULL) {
        cout << aux->val << " ";
        aux = aux->next;
    }
    cout << endl;

    aux = Solution().sortList(head);

    // -1,0,3,4,5
    while (aux != NULL) {
        cout << aux->val << " ";
        aux = aux->next;
    }
    cout << endl;

    return 0;
}
