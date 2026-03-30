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
    bool isPalindrome(ListNode* head) {
        vector<int> pa;
        ListNode* cur = head;
        while (cur) {
            pa.push_back(cur->val);
            cur = cur->next;
        }
        int l = 0;
        int r = pa.size() - 1;
        while (l <= r) {
            if (pa[l++] != pa[r--]) {
                return false;
            }
        }
        return true;
    }
};