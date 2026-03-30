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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       int N = 0;
       ListNode* cur = head;
       while (cur) {
        N++;
        cur = cur->next;
       }
       int ri = N - n;
       if (ri == 0) {
        return head->next;
       }
       cur = head;
       for(int i=0; i < ri; i++) {
        if (i+1 == ri) {
            cur->next = cur->next->next;
        }
        cur = cur->next;
       }
       return head;
    }
};
