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
        int len=0;
        ListNode* cr=head;
        while(cr!=NULL)
        {
            len++;
            cr=cr->next;
        }
        int fromFirst=len-n+1;
        if(fromFirst==1)
        {
            return head->next;
        }
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* nxt=head;
        if(head!=NULL)
        {
            nxt=nxt->next;
        }
        int c=1;
        while(c<fromFirst)
        {
            prev=cur;
            cur=nxt;
            if(nxt!=NULL)
            nxt=nxt->next;
            c++;
        }
        prev->next=nxt;
        return head;
    }
};