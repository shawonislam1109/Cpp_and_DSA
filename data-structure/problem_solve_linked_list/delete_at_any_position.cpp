class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Create a dummy node to handle edge cases (e.g., removing the first node)
        ListNode *dummy = new ListNode(0, head);
        ListNode *fast = dummy, *slow = dummy;

        // Move the fast pointer `n + 1` steps ahead
        for (int i = 0; i <= n; i++)
        {
            if (fast == nullptr)
                return head; // Edge case: n is greater than the length of the list
            fast = fast->next;
        }

        // Move both fast and slow pointers until fast reaches the end
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Slow is now pointing to the node before the one to be deleted
        ListNode *toDelete = slow->next;
        slow->next = toDelete->next;
        delete toDelete;

        // Return the head of the modified list
        ListNode *newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return newHead;
    }
};
