/*
Trapping Rain Water 
https://leetcode.com/problems/trapping-rain-water/
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/
/*
Intitution:
  The Two Pointer technique can be used to solve the Trapping Rain Water problem. 
  This problem involves finding the amount of water that can be trapped between bars of varying heights arranged in a line.
  
Algorithm:
  Initialize two pointers: one at the beginning of the array and the other at the end.
  Initialize two variables to keep track of the maximum height of bars on the left and right side.
  Initialize a variable to keep track of the total water trapped.
  While the left pointer is less than the right pointer, do the following:
  If the height of the left bar is less than the height of the right bar, update the maximum height of bars on the left side and add the difference between the maximum height and the height of the current bar to the total water trapped.
  Else, update the maximum height of bars on the right side and add the difference between the maximum height and the height o6f the current bar to the total water trapped.
  Move the pointer that is pointing to the shorter bar towards the center.
  Once the two pointers meet, return the total water trapped.
*/

class Solution {
public:
    int trap(vector<int>& arr) {
        int l = 0,h=arr.size()-1;
        int lmax=0,rmax=0;
        int tot=0;
        while(l<h){
            if(arr[l]<arr[h]){
                if(arr[l]>lmax){
                    lmax=arr[l];
                }
                else{
                    tot+=lmax - arr[l];
                }
                l++;
            }
            else{
                if(arr[h]>rmax){
                    rmax=arr[h];
                }
                else{
                    tot+=rmax - arr[h];
                }
                h--;
            }
        }
        return tot;
    }
};
