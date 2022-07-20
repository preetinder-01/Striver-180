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
};


/* recursive 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==0){//
            return head;              //
        }
        ListNode *last=reverseList(head->next);
        //last should be a pointer
        head->next->next=head;
        head->next=0;
        return last;
    }
};*/