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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode dummy(0);
        ListNode* temp = &dummy;
        while(l1&&l2){
            int total=l1->val+l2->val+carry;
            carry=total/10;
            ListNode* node = new ListNode(total%10);
            temp->next=node;
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int total=l1->val+carry;
            carry=total/10;
            ListNode* node = new ListNode(total%10);
            temp->next=node;
            temp=temp->next;
            l1=l1->next;
        }
        while(l2){
            int total=l2->val+carry;
            carry=total/10;
            ListNode* node = new ListNode(total%10);
            temp->next=node;
            temp=temp->next;
            l2=l2->next;
        }
        if(carry){
            ListNode* node = new ListNode(carry);
            temp->next=node;
        }
        return dummy.next;
    }
};
