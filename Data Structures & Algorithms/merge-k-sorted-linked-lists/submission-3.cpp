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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (ListNode* l : lists) {
            pq.push(l);
        }
        ListNode* head = new ListNode();
        ListNode* cur = head;
        while (!pq.empty()) {
            ListNode* t = pq.top();
            pq.pop();
            cur->next = t;
            cur = cur->next;
            if (t->next) {
                pq.push(t->next);
            }
        }
        return head->next;
    }
};
