// Rotate List

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || (!head -> next))
            return head;
        ListNode* first = head;
        ListNode* second = head;
        int len = 0;
        while(second -> next) {
            len++;
            second = second -> next;
        }
        len++;
        k = k%len;
        int shift = len - k;
        shift--;
        while(shift--) {
            first = first -> next;
        }
        second -> next = head;
        ListNode* newHead = first -> next;
        first -> next = NULL;
        return newHead;
    }
};