/*
75.Sort Colors
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.
Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid = 0;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low++],nums[mid++]);
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high--]);
            }
        }
    }
};
/*
We use "Dutch national flag problem" to solve this problem,
The code starts with three pointers: low, mid, and high. Initially, 
low points to the start of the array, high points to the end of the array, 
and mid points to the first unprocessed element in the array. 
The idea is to use the mid pointer to traverse the array and swap elements as necessary to group all 0s at the beginning of the array, 
all 1s in the middle, and all 2s at the end.
The while loop runs until the mid pointer reaches the high pointer. 
During each iteration of the loop, we check the value of the mid element and perform the following operations:
If the mid element is 0, we swap it with the element at the low pointer and increment both mid and low. 
This moves all 0s to the beginning of the array.
If the mid element is 1, we don't need to do anything and just increment mid. This leaves all 1s in the middle of the array.
If the mid element is 2, we swap it with the element at the high pointer and decrement high. This moves all 2s to the end of the array.
After the loop finishes, the array will be sorted as desired.
Overall, this is an efficient O(n) solution to the problem that uses only constant extra space.
*/
