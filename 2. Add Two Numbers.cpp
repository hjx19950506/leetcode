/*
用小学学加减法的思维从低位向高位加， 注意进位即可
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *p = NULL;
        int sum = 0, carry = 0, n1 = 0, n2 = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            if (l1 != NULL) {
                n1 = l1->val;
                l1 = l1->next;
            }
            else
                n1 = 0;
            if (l2 != NULL) {
                n2 = l2->val;
                l2 = l2->next;
            }
            else
                n2 = 0;
                
            sum = n1 + n2 + carry;
            if (sum > 9) {
                carry = 1;
                sum %= 10;
            }
            else
                carry = 0;
            ListNode *newNode = new ListNode(sum);
            if (head == NULL) {
                head = newNode;
                p = newNode;
            } else {
                p->next = newNode;   
                p = p->next;
            }
            sum = 0;
        }
        return head;
    }
};