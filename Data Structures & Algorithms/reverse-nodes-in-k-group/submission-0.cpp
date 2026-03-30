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
    ListNode* reverse(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        while (cur != NULL) {
            ListNode* t = cur->next;
            cur->next = prev;
            prev = cur;
            cur = t;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       int tempk = k;
       ListNode* nh = new ListNode(0);
       nh->next = head;
       ListNode* cur = nh;
       ListNode* prev = nh;
       while (prev != NULL) {
        prev = prev->next;
        tempk--;
        if (tempk == 0 && prev) {
            ListNode* t = prev->next;
            ListNode* start = cur->next;
            prev->next = NULL;
            cur->next = reverse(start);
            start->next = t;
            cur = start;
            prev = start;
            tempk = k;
        }
       }
       return nh->next;
    }
};
