# # https://leetcode.com/problems/add-to-array-form-of-integer/description/
# # Time complexity - max(len(nums),k)
# # space complexity - O(1) -- if answer answer not included else O(N)

# """
# rtype -> integer array
# """

# """
# Intuition:

# simply iterate over the number array from reverse direction and take last digit of k and don't forget to add carry 
# after performing addition take % 10 of the sum and add it to the answer and for carry: carry= sum // 10 
# now append it to the answer array 
# """

# import math
# def solution(num,k) -> list():
#     # Number of digits in the number k
#     digits = int(math.log10(k))+1
#     carry , i = 0 , len(num) - 1
#     ans = []
#     # number to times to iterate 
#     maximum = max(digits,len(num))

#     while maximum:
#         # first check if index is within range if it is then val1 = num[i] else 0 
#         val1 = num[i] if i >= 0 else 0
#         # last digit of the number k
#         val2 = k % 10 
#         # removing the remainder
#         k = k // 10 
#         # As discussed performing addition and appending
#         sum = val1 + val2 + carry
#         ans.append(sum % 10)
#         carry = sum // 10
#         i -= 1
#         maximum -= 1 
#     # after performing all the the addition of the number then also the carry is remaining then append it to the answer
#     if carry != 0:
#         ans.append(carry)
#     # because we have appended the values in the array 
#     return ans[::-1]

# # try for these values and you will get it
# print(solution([2,7,4], 806))
# print(solution([1], 1000))
# print(solution([1,0,0,0,0], 10))
