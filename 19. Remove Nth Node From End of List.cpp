/*
双指针，一个提前走n步
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode *p_pre = newhead, *p_now = newhead;
        while (n > 0) {
            p_pre = p_pre->next;
            n--;
        }
        if (n != 0)
            return newhead->next;
        while (p_pre->next != NULL) {
            p_pre = p_pre->next;
            p_now = p_now->next;
        }
        p_now->next = p_now->next->next;
        
        return newhead->next;
    }
};