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
    ListNode* merge(ListNode* l1, ListNode* l2) {
       ListNode* nh = new ListNode(0);
       ListNode* cur = nh;
       while (l1 && l2) {
        if (l1->val <= l2->val) {
            cur->next = l1;
            l1 = l1->next; 
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
       }
       if (l1) {
        cur->next = l1;
       }
       if (l2) {
        cur->next = l2;
       }
       return nh->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       if (lists.empty()) {
        return NULL;
       }
       ListNode* prev = lists[0];
       for (int i=1; i<lists.size(); i++) {
        prev = merge(prev, lists[i]);
       }
       return prev;
    }
};
