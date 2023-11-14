/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode prevptr = null;
        ListNode current = head;
        ListNode nextptr = null;
        while(current != null){
            nextptr = current.next;
            current.next = prevptr;
            prevptr = current;
            current = nextptr;
        }
        return prevptr;
    }
}