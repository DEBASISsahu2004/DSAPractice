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
        ListNode *s = head, *f = head;

        for(int i=0; i<n; i++){
            f = f->next;
        }

        if (!f) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        while(f && f->next){
            s = s->next;
            f = f->next;
        }

        ListNode *temp = s->next;
        s->next = s->next->next;
        delete temp;

        return head;
    }
};