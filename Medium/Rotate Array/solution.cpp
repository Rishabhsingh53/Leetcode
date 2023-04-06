/*
189. Rotate Array

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n;
        for(int i = 0,j=n-1;i<j;i++,j--){
            swap(arr[i],arr[j]);
        }
        for(int i = 0,j=k-1;i<j;i++,j--){
            swap(arr[i],arr[j]);
        }
        for(int i = k,j=n-1;i<j;i++,j--){
            swap(arr[i],arr[j]);
        }
    }
};

/*
The rotate function takes an input array arr and an integer k, and rotates the array to the right by k positions. 
The function first determines the effective number of positions to rotate k by using the modulo operator %. 
It then splits the array into two parts: the first n-k elements and the last k elements. 
It reverses both of these parts separately using a two-pointer technique with two for loops. 
Finally, it reverses the entire array to obtain the rotated array.

In the main function, we create an example input array arr and integer k, 
and call the rotate function on it using an instance of the Solution class. We print out the rotated array after calling the function.
*/
