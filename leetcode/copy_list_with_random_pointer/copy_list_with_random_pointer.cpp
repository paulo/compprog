#include <bits/stdc++.h>

using namespace std;

#define pb push_back

class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        Node *auxHead = head, *aux = NULL;
        while (auxHead != NULL) {
            aux = new Node(auxHead->val);
            aux->next = auxHead->next;
            auxHead->next = aux;
            auxHead = auxHead->next->next;
        }

        auxHead = head;
        while (auxHead != NULL) {
            if (auxHead->random != NULL) {
                auxHead->next->random = auxHead->random->next;
            }
            auxHead = auxHead->next->next;
        }

        auxHead = head;
        Node *res = NULL, *resHead = NULL;
        while (auxHead != NULL) {
            if (res == NULL) {
                res = auxHead->next;
                resHead = res;
            } else {
                res->next = auxHead->next;
                res = res->next;
            }

            auxHead->next = auxHead->next->next;
            auxHead = auxHead->next;
        }

        return resHead;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
