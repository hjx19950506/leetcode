/*
双指针，逐个处理
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        ListNode *p1 = l1, *p2 = l2;
        ListNode *newhead, *p_cur;
        if (p1->val < p2->val) {
            newhead = p1;
            p1 = p1->next;
        }
        else {
            newhead = p2;
            p2 = p2->next;
        }
        p_cur = newhead;
        while (p1 != NULL || p2 != NULL) {
            if (p2 == NULL || (p1 != NULL && p1->val < p2->val)) {
                p_cur->next = p1;
                p_cur = p_cur->next;
                p1 = p1->next;
            }
            else if (p1 == NULL || (p2 != NULL && p1->val >= p2->val)) {
                p_cur->next = p2;
                p_cur = p_cur->next;
                p2 = p2->next;
            }
        }
        return newhead; 
    }
};