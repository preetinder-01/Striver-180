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
    
    ListNode* reverseList(ListNode* head) {
        ListNode *prevnode=NULL,*currnode=head,*nextnode=head;
        while(nextnode!=NULL)
        {
            nextnode=nextnode->next;
            currnode->next=prevnode;
            prevnode=currnode;
            currnode=nextnode;
        }head=prevnode;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *fast=head;
        ListNode*slow=head;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=reverseList(slow);
        fast=head;
        while(slow and fast)
        {
            if(slow->val!=fast->val)
                return 0;
            slow=slow->next;
            fast=fast->next;
        }
        return 1;
    }
};