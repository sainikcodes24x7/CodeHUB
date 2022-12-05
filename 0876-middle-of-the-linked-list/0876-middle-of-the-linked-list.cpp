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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* temp=head;
        ListNode* temp2=head;
        int count=0;
        while(temp2)
        {
            count++;
            temp2=temp2->next;
        }
        cout<<count;
        int k=0;
        while(k<(count/2))
        {
            k++;
            temp=temp->next;
        }
        head=temp;
        return head;
    }
};