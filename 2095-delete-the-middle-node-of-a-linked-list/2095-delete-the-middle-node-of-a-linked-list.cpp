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
    int length(ListNode* head)
    {
        int c=0;
        ListNode*temp=head;
        while(temp)
        {
            temp=temp->next;
            c++;
        }
        return c;
    }
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(length(head)==1)
            return NULL;
        if(length(head)%2==0)
        {
            slow->next=slow->next->next;
        }
        else
        {
            slow->val=slow->next->val;
            slow->next=slow->next->next;
            //return head;
        }
        return head;
    }
};