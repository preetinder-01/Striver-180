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
     ListNode* l3=new ListNode() ;
        ListNode*first=l1;
        ListNode*second=l2;
        ListNode* third=l3;
        int sum=0,carry=0;
        while(first and second)
        {
            sum+=first->val+second->val+carry;
            if(sum>=10)
            {
                carry=1;sum-=10;
                ListNode *temp=new ListNode(sum);
                third->next=temp;
                third=third->next;
                sum=0;
            }
            else
                {
                ListNode *temp=new ListNode(sum);
                third->next=temp;
                third=third->next;
                sum=0;carry=0;
                }
            first=first->next;
            second=second->next;
        }
        while(first)
        {
            sum=first->val+carry;
            if(sum>=10)
            {
                carry=1;sum-=10;
                ListNode *temp=new ListNode(sum);
                third->next=temp;
                third=third->next;
                sum=0;
            }
            else
                {
                ListNode *temp=new ListNode(sum);
                third->next=temp;
                third=third->next;
                sum=0;carry=0;
                }
            first=first->next;
            
            
        }
        while(second)
        {
            sum=second->val+carry;
            if(sum>=10)
            {
                carry=1;sum-=10;
                ListNode *temp=new ListNode(sum);
                third->next=temp;
                third=third->next;
                sum=0;
            }
            else
                {
                ListNode *temp=new ListNode(sum);
                third->next=temp;
                third=third->next;
                sum=0;carry=0;
                }
            second=second->next;
        }
        if(carry)
        {ListNode *temp=new ListNode(carry);
        third->next=temp;}
        return l3->next;;
    }
};