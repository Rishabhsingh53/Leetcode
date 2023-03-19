class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long result=0;
        for(auto x:nums){
            result^=x;
        }
        long long mask  = (result & ~(result-1));
        int x=0;
        
        for(auto i:nums){
            if((i&mask) >0){
                x^=i;
            }
        }
        int y = result^x;

        return vector<int> {x,y};
    }
};
/*
Here's how the code works:

The first for-loop iterates through the array of integers nums and XOR's all the elements with the variable result. 
Since the XOR operator is commutative and associative, this leaves result as the XOR of the two unique numbers we are looking for.
We then find a bit mask mask that isolates the rightmost bit where the two unique numbers differ. 
This is done by taking the bitwise AND of result with its two's complement (negation and increment by one), 
which results in only the rightmost bit where result has a 1.
We then iterate through the array of integers nums again, and for each element i, 
we check if the mask bit is set by taking the bitwise AND of i and mask. If this value is greater than zero, 
then i has the bit that differs between the two unique numbers, so we XOR it with x.
Finally, we obtain the second unique number y by taking the XOR of result and x.
The function returns a vector containing the two unique numbers x and y.
Overall, this algorithm has a time complexity of O(n) and a space complexity of O(1), 
since we only use a constant amount of additional memory to store the two unique numbers.
*/
