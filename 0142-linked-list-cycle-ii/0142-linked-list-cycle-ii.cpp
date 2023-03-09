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
        ListNode* slow=head;
        ListNode* fst=head;
        while(fst!=NULL)
        {
            fst=fst->next;
            if(fst!=NULL)
            {
                fst=fst->next;
            }
            slow=slow->next;
            if(slow==fst)
            {
                break;
            }
        }
        if(fst==NULL)
        {
            return fst;
        }
        slow=head;
        while(fst!=slow)
        {
            fst=fst->next;
            slow=slow->next;
        }
        return slow;
    }
};