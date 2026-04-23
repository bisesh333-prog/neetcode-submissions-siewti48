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
        ListNode* dummy = new ListNode(0,head);
        ListNode* t1 = dummy;
        ListNode* t2 = head;
        while(n){
            t2=t2->next;
            n--;
        }
        while(t2){
            t1=t1->next;
            t2=t2->next;
        }
        ListNode* tl1 = t1->next->next;
        ListNode* tl2 = t1->next;
        t1->next=tl1;
        delete(tl2);
        return dummy->next;
    }
};
