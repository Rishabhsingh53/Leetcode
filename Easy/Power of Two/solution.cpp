/*
231. Power of Two
Problem statement:
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2^x.

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
*/
/*
In order to solve this problem we use bit manipulation technique where in n&n-1 operation if results to 0 than it is an power of 2
if(n&n-1 ==0) -> n is power of 2

additionally 0  being a border case needs to be solved separately 
if input n is 0 we return false

therefore our solution becomes 
n && (! n&n-1)
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n && (!(n & (n-1)));
    }
};
