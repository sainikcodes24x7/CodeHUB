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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int len=length(head); //2
        int k=len-n+1;  //1
        if(k==1)
        {
            head=head->next;
        }
        int cnt=1;
        while(temp)
        {
            if(cnt==k-1)
            {
                temp->next=temp->next->next;
            }
            temp=temp->next;
            cnt++;
        }
        return head;
    }
};