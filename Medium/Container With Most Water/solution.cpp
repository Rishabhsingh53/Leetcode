/*
11.Container With Most Water https://leetcode.com/problems/container-with-most-water/
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int left = 0; 
        int right = height.size() - 1;
        while (left < right) {
            int width = right - left;
            maxarea = max(maxarea, min(height[left], height[right]) * width);
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxarea;
    }
};
/*
Explanation: 
The approach used here is the two-pointer technique, which works by starting with two pointers at the beginning and end of the array 
and moving them towards each other. At each iteration, the width of the container is calculated as the difference between the two pointers, 
and the area is calculated as the minimum height between the two pointers multiplied by the width. The maximum area is then updated as needed.

Overall, this solution has a time complexity of O(n) and a space complexity of O(1), where n is the size of the input array.

    maxarea = 0
    left = 0
    right = height.length - 1
    while left < right:
        width = right - left
        area = min(height[left], height[right]) * width
        maxarea = max(maxarea, area)
        if height[left] <= height[right]:
            left = left + 1
        else:
            right = right - 1
    return maxarea
*/
