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
    int pairSum(ListNode* head) {
       ListNode* slow = head; 
       ListNode* fast = head;
       while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
       }
       ListNode* cur = NULL;
       ListNode* first = head;
       while (slow) {
            ListNode* nxt = slow->next;
            slow->next = cur;
            cur = slow;
            slow = nxt;
       }
       ListNode* second = cur;
       int res = 0;
       while (second) {
            res = max(res, first->val + second->val);
            first = first->next;
            second = second->next;
       }
       return res;
    }
};