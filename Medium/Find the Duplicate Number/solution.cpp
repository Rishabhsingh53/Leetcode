/* 
287. Find the Duplicate Number https://leetcode.com/problems/find-the-duplicate-number/

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};

/*
Intitution and explanation:
The technique involves utilizing two pointers, a slow pointer called the "tortoise" and a fast pointer known as the "hare" to detect a cycle within a linked list. The idea is that if a cycle exists, the fast pointer will eventually catch up to the slow pointer.
In this code, the integer array is treated as a linked list, where each element of the array represents a node, and the value of the element signifies the index of the next node. For instance, if nums[0] = 3, then it implies that the first node points to the fourth node (assuming 0-based indexing).
To locate the duplicate element, the algorithm initially identifies the point of intersection of the two runners using Floyd's cycle-finding algorithm. The tortoise moves one step at a time, while the hare moves two steps at a time until they meet at a common point. At this point, it's known that a cycle exists within the linked list.
Subsequently, the algorithm locates the entrance to the cycle by resetting the tortoise to the first element of the array and moving both the tortoise and hare one step at a time until they meet at the entrance to the cycle. This is because the distance from the first element to the entrance of the cycle is the same as the distance from the intersection point to the entrance of the cycle.
Finally, the algorithm returns the value of the hare.
*/
