Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (head == NULL)
            return head;
        if (k == 0)
            return head;
        int size = 1;
        ListNode *tail = head;
        while(tail->next!=NULL)
        {
            tail = tail->next;
            size++;
        }
        k = k % size;
        if (k == 0 || size == 1)
            return head;
        ListNode* newHead = head;
        ListNode* new_head_previous = head;
        // find out the new tail e.g. the node right before the new head
        for (int i = 1; i <= size - k - 1; ++i)
        {
            new_head_previous = new_head_previous->next;
        }
        newHead = new_head_previous->next;
        
        tail->next = head; // the old tail now points to the old head
        new_head_previous->next = NULL; // the new_head_previous becomes the new tail
        return newHead;
        
        
        
    }
};