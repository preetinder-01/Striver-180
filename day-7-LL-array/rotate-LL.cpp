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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) //If this simply return head.
            return head;
        
        int Node_count=0; //Keep Node Count.
        ListNode* curr=head; 
        ListNode* tail=NULL; //Keep the record of end of given Link-List.
        ListNode* new_head; //Keep the record of new head.
        while(curr!=NULL)
        {
            Node_count++;
            tail=curr; //Keep the record of tail.
            curr=curr->next;
        }
        
        if(k%Node_count==0) //If this means no rotation is necessary.
            return head;
        
        k=k%Node_count; // Actual rotation require. -->Updated k.
        int count=0; // it will keep the record of  kth node from end.
        curr=head; //For calculation.
        while(true)
        {
          count++; //Increment the count.
            if(count==Node_count-k) //If we find k th node from end (cuur->next is our kth node from end ,means curr is one node before it.)
            {
                new_head=curr->next; //Update our new head, with kth node from end.
                curr->next=NULL; //MAke the curr-Next null.
                tail->next=head; //Attach head to next of tail.
                head=new_head; //Update the head with new head.
                break; //Break the Loop
            }
            curr=curr->next; //Jump to next node
        }
        
        return head; //Return the Updated head.
    }
};