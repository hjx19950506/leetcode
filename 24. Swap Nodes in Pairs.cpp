/*
×¢Òâ±ß½ç
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void ExchangNandNN(ListNode* l) {
        ListNode *nn = l->next->next;
        l->next->next = nn->next;
        nn->next = l->next;
        l->next = nn;
    }
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
        return head;
        
        ListNode *p = new ListNode(0);
        p->next = head;
        head = head->next;
        while (p->next != NULL && p->next->next != NULL) {
            ExchangNandNN(p);
            p = p->next->next;
        }
        return head;
    }
};