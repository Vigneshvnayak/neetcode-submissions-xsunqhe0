/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       int num1 = 0, num2 = 0; 
       while (l1) {
            num1 = num1 * 10 + l1->val;
            l1 = l1->next;
       }
       while (l2) {
            num2 = num2 * 10 + l2->val;
            l2 = l2->next;
       }
       int num3 = num1 + num2;
       if (num3 == 0) return (new ListNode());
       ListNode* cur = NULL;
       while (num3 > 0) {
            int rem = num3 % 10;
            num3 = num3 / 10;
            ListNode* nn = new ListNode(rem);
            nn->next = cur;
            cur = nn;
       }
       return cur;
    }
};