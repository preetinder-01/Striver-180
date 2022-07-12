/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *ptr=head;
        if(head==NULL)
            return head;
        while(ptr)
        {
            Node* temp=new Node(ptr->val);
            temp->next=ptr->next;
            ptr->next=temp;
            ptr=(ptr->next)->next;
        }
        Node *iter=head;
        while(iter)
        {
            iter->next->random=iter->random?iter->random->next:iter->random;
            // curr->next->random=curr->random?curr->random->next:curr->random;
            iter=iter->next?iter->next->next:iter->next;
        }
        iter=head;
        ptr=iter->next;
        Node* new_head=head->next;
        
        while(ptr and iter )
        {
            iter->next=iter->next?iter->next->next:iter->next;
            ptr->next=ptr->next?ptr->next->next:ptr->next;
            iter=iter->next;
            ptr=ptr->next;
        }
        return new_head;
    }
};