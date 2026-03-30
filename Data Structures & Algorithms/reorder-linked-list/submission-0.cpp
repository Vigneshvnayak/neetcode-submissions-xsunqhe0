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
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head; 
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                break;
            }
        }
        ListNode* l1 = head;
        ListNode* l2 = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        while (l2) {
            ListNode* t = l2->next;
            l2->next = prev;
            prev = l2;
            l2 = t;
        }
        l2 = prev;
        while (l2) {
            ListNode* t1 = l1->next;
            ListNode* t2 = l2->next;
            l1->next = l2;
            l2->next = t1;
            l1 = t1;
            l2 = t2;
        }
    }

};
