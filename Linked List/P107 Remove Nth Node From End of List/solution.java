class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy_head = new ListNode(0);
        dummy_head.next = head;

        ListNode slow = dummy_head;
        ListNode fast = dummy_head;

        // Move fast pointer n nodes ahead
        for (int i = 0; i < n; i++) {
            if (fast.next == null) {
                // If n is greater than the length of the list,
                // we'll remove the head node
                return head.next;
            }
            fast = fast.next;
        }

        // Move both pointers until fast reaches the end
        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }

        // Remove the nth node from the end
        slow.next = slow.next.next;

        return dummy_head.next;
    }
}