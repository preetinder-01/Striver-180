/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // iterate using two pointers fast and slow until fast fast ==slow
        // where they meet that is cycle startng node and get uska position
        if(!head ||!head->next)
            return nullptr;
        ListNode *fast = head, *slow = head;
        while(fast && fast->next &&slow)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                fast = head;
                while (fast != slow) {                    
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
        }
        
    
};