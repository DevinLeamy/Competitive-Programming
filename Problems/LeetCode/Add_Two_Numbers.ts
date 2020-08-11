/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    var res = new ListNode(0);
    var front = res;
    var carry = false;
    while (l1 || l2 || carry) {
        var sum = 0;
        if (l1) {
            sum += l1.val;
            l1 = l1.next;
        } 
        if (l2) {
            sum += l2.val;
            l2 = l2.next;
        }
        if (carry) {
            sum += 1;
        }
        res.val = sum % 10;
        if (sum >= 10) {
            carry = true;
        } else {
            carry = false;
        }
        if (l1 || l2 || carry) {
            res.next = new ListNode(0);
            res = res.next
        }
    }
    return front;
};
