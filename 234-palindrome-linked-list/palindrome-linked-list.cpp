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
        ListNode* t1 = head;
        ListNode* t2 = head;
        stack<int> s;

        while (t2 && t2->next) {
            s.push(t1->val);
            t1 = t1->next;
            t2 = t2->next->next;
        }

        if (t2) {
            t1 = t1->next;
        }

        while (t1) {
            if (t1->val == s.top()) {
                s.pop();
                t1 = t1->next;
            } else {
                return false;
            }
        }

        return true;
    }
};