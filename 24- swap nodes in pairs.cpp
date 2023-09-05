class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       if (head == nullptr ||
            head->next == nullptr) {
            return head;
        }
        
        ListNode * prev = nullptr;
        ListNode * curr = head;
        ListNode * nxt  = head->next;
        
        head = head->next;
        
        while (curr && nxt) {
            if (prev)
                prev->next = nxt;
            curr->next = nxt->next;
            nxt->next = curr;
            prev = curr;
            curr = curr->next;
            if (curr)
                nxt = curr->next;
        }
        
        return head; 
    }
};