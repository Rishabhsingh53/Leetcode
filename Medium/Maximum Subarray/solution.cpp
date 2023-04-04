/*
53. Maximum Subarray

Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int sum=0;
        if(nums.size() ==1){
            return nums[0];
        }
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            res=max(res,sum);
            if(sum<0){
                sum=0;
            }
        }
        return res;
    }
};

/*
Using Kadane's algorithm
The function works by iterating over the elements of the input vector nums using a for loop. For each element, the function adds the element to a running sum sum. 
If the running sum becomes negative, it is reset to zero because any negative subarray sum will only decrease the maximum sum we are trying to find. 
The function also keeps track of the maximum sum seen so far in the variable res. 
At each iteration, res is updated to be the maximum of the current res and the current sum. Finally, the function returns res, 
which holds the maximum sum of a contiguous subarray.

The if condition at the beginning checks if the vector nums has only one element. 
If this is the case, the function returns that single element as it is the maximum subarray sum possible for a vector with only one element.

Note that this algorithm has a time complexity of O(n) where n is the length of the input vector nums. 
This is because the algorithm only needs to iterate once through the vector to compute the maximum subarray sum.
*/
