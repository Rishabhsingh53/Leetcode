"""
Partition List 
https://leetcode.com/problems/partition-list/description/
"""
"""
Intitution:
  The idea is to create to different linked list 
  list 1 for all elements smaller than x 
  list 2 for all elements greater than or equal to x 
  atlast join both list
  
Algorithm:
  first create two linked lists 
  we require 4 pointers head1 , head2 of list1 and list2 respectively and 
  temp1 , temp2 of list1 and list2.

  now we iterate in the original list 
  if the element is smaller than we append it to the list1 
  else append to list2 
  
  lastly we combine both the lists 
  the temp1 is pointing to the last node in the list1 we need it to point to starting node of list2 

"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        head1 = ListNode(0)
        head2 = ListNode(0)
        temp1 = head1
        temp2 = head2 

        while head:
            if head.val < x:
                new = ListNode(head.val)
                temp1.next = new 
                temp1 = new
            else:
                new = ListNode(head.val)
                temp2.next = new 
                temp2 = new
            head = head.next 
        
        temp1.next =  head2.next 
        return head1.next 