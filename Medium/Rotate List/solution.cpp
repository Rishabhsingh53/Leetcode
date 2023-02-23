/*
61. Rotate List https://leetcode.com/problems/rotate-list/

Given the head of a linked list, rotate the list to the right by k places.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0){
            return head;
        }
        int len = 1;
        ListNode* curr=head;
        while(curr->next!=NULL){
            ++len;
            curr=curr->next;
        }
        curr->next = head;
        k = k % len;
        k = len - k;
        while(k--){
            curr=curr->next;
        }
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};

/*
Explanation
The method first checks if the head of the linked list is null, or if there is only one element in the list, or if k is 0, then it returns the head itself as there is no rotation required.

Then, it counts the length of the linked list using a variable len and a loop that iterates until the end of the list is reached.

Next, it connects the last element of the list to the first element of the list, making it a circular list, which will help in rotating the list.

It then calculates the actual number of rotations required by using modulo operation on k with the len of the linked list, and assigns it back to k. This is because if k is greater than or equal to the len of the list, then rotating k places is equivalent to rotating k%len places.

Then, it sets k to the number of elements to move from the start of the list, which is len-k.

After that, it iterates through the linked list k times, which brings the curr pointer to the element that needs to be the new head of the rotated list.

Finally, it sets the head pointer to the new head of the rotated list, sets the next pointer of the previous element to NULL to break the circular list, and returns the head pointer.

In summary, this method rotates a singly linked list k places to the right and returns a new head of the rotated list.
*/
