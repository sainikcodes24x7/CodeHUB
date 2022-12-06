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
    ListNode* oddEvenList(ListNode* head) {
        ListNode ph[2];
        ListNode* p[2] = {&ph[0], &ph[1]};
        bool odd = false;
        while (head) {
            p[odd] = p[odd]->next = head;
            head = head->next;
            odd = !odd;
        }
        p[0]->next = ph[1].next;
        p[1]->next = nullptr;
        return ph[0].next;
    }
};