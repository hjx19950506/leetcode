/*
类似上一题
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
    ListNode* reverseKOne(ListNode *pre, int k) {
        vector<ListNode*> lnps;
        ListNode *p = pre;
        for (int i = 0; i < k; i++) {
            ListNode *tmp = new ListNode(0);
            tmp = p->next;
            lnps.push_back(tmp);
            p = p->next;
        }
        pre->next = lnps.back();
        lnps[0]->next = lnps.back()->next;
        for (int i = k-1; i > 0; i--) {
            lnps[i]->next = lnps[i-1];
        }
        return lnps[0];
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        
        ListNode *pre = new ListNode(0);
        pre->next = head;
        ListNode *p = pre;
        while (1) {
            
            ListNode *test = p;
            int n = k;
            while (n && test->next) {
                test = test->next;
                n--;
            }
            if (n == 0)
                p = reverseKOne(p, k);
            else
                break;
        }
        return pre->next;
    }
};