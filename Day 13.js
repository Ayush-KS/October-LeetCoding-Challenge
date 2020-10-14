// Sort List

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */

var findMid = function(head) {
    if(!head || !head.next || !head.next.next)
        return head;
    let fast = slow = head;
    while (fast && fast.next) {
        fast = fast.next.next;
        slow = slow.next;
    }
    return slow;
};

var merge = function(head1, head2) {
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    if(head1.val < head2.val) {
        head1.next = merge(head1.next, head2);
        return head1;
    }
    head2.next = merge(head1, head2.next);
    return head2;
}

var sortList = function(head) {
    if(!head || !head.next)
        return head;
    let mid = findMid(head);
    
    let head2 = sortList(mid.next);
    mid.next = null;
    head = sortList(head);
    
    return merge(head, head2);
};