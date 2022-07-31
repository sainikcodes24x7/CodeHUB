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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
  /*      ListNode*temp=head;
        ListNode*temp2=head;
        while(temp->val!=left)
        {
            temp=temp->next;
        }
        while(temp2->val!=right)
        {
            temp2=temp2->next;
        }
        temp2=temp2->next;
        ListNode*prevptr=temp;
        ListNode*currptr=temp->next;
        ListNode*nextptr;
        while(currptr->val!=temp->val)
        {
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
        }
        return prevptr; */
        if(!head->next || m == n) 
            return head;
        ListNode* l = head;
        for(int i = 0; i < m-2; i++) 
            l = l->next;
        
        ListNode* pre = NULL;
    //    if(m==1)
     //       ListNode* cur = l;
    //    else
    //        ListNode* cur=l->next;
       ListNode* cur = m == 1 ? l : l->next;
        ListNode* next = cur->next;
        ListNode* reverseHead = cur;
        for(int i = 0; i < n-m+1; i++){
            cur->next = pre;
            pre = cur;
            cur = next;
            next = next ? next->next : NULL;
        }
        reverseHead->next = cur;
        if(m != 1) l->next = pre;
        return m == 1 ? pre : head;
    
    }
};