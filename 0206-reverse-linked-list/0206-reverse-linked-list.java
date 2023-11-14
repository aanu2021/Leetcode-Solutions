class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode nextNode = head.next;
        nextNode = reverseList(nextNode);
        head.next.next = head;
        head.next = null;
        return nextNode;
    }
}