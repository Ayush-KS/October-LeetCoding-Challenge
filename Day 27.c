// Linked List Cycle II

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow, *fast;
    slow = head;
    fast = head;
    
    do {
        if(!fast || !fast -> next)
            return NULL;
        slow = slow -> next;
        fast = fast -> next -> next;
    } while(slow != fast);
    
    slow = head;
    
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }
    
    return slow;
}