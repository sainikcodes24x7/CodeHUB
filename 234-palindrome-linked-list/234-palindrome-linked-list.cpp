#include<stack>
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
    bool isPalindrome(ListNode* head) {
       ListNode* temp=head;
        ListNode* slow=head;
        ListNode* fast=head;
        stack<int>st;
        //stack<int>st2;
        //stack<int>st3;
        while(fast && fast->next)
        {
            st.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast)
        {
            slow=slow->next;
        }
        while(slow)
        {
            if(slow->val!=st.top())
                return false;
            else
            {
                st.pop();
                slow=slow->next;
            }
        }
        return true;
    }
};