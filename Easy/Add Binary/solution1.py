""" 
https://leetcode.com/problems/add-binary/
"""

"""
Intuition:
if we have 3 '1' w.r.t a[i] , b[j] and carry then
carry = 1 and ( addtion of a[i] , b[j] and carry = 1 )

if we have 2 '1' w.r.t a[i], b[j] and carry then
carry = 1 and ( addtion of a[i] , b[j] and carry = 0 )

if we have 1 '1' w.r.t a[i] , b[j] and carry then
carry = 0 and ( addtion of a[i] , b[j] and carry = 1 )

if we have 0 '1' w.r.t a[i] , b[j] and carry then
carry = 0 and ( addtion of a[i] , b[j] and carry = 0 )

Approach:
simple iterate the string a and string b and carry is not empty
with carry not empty I mean not zero
Iterate in reverse order for addition
Every time we initialize ones with 0 and if we see a '1' we increment the count of ones
"""

def addBinary(a,b):
    ans = ""
    i = len(a) - 1
    j = len(b) - 1
    carry = 0

    while i >= 0 or j >= 0 or carry:
        ones = 0
        if i >= 0 and a[i] == '1':
            ones += 1 
        if j >= 0 and b[j] == '1':
            ones += 1 
        if carry == 1:
            ones += 1 
        
        if ones == 0:
            ans = ans + "0"
        elif ones == 1:
            ans = ans + '1'
            carry = 0
        elif ones == 2:
            ans = ans + '0'
            carry = 1
        else:
            ans = ans + '1'
            carry = 1

        i -= 1 
        j -= 1 
    return ans[::-1]
