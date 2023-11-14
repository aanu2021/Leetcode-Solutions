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
    
    public ListNode reverseList(ListNode head){
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
    
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null) return true;
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null && fast.next != null && fast.next.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        ListNode firstPointer = head;
        ListNode secondPointer = slow.next;
        slow.next = null;
        secondPointer = reverseList(secondPointer);
        while(firstPointer != null && secondPointer != null){
            if(firstPointer.val != secondPointer.val) return false;
            firstPointer = firstPointer.next;
            secondPointer = secondPointer.next;
        }
        return true;
    }
}

// 1 -> 2 -> 3 -> 2 -> 1
//           s
//                     f
                    
// 1 -> 2 -> 3 -> 3 -> 2 -> 1
//           s
//                     f
                         
    
    