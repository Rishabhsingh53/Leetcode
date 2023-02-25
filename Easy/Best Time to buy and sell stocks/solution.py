"""
Partition List 
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
"""
"""
Intitution:
The idea is to obtain the maximum profit we buy on the day where the stock is minimum and sell on the day where the profit from minimum is maximum.

  
Algorithm:
  We assume the minimum stock price to be on day1 
  then we iterate over the array if the element is lower than the current minimum we update minimum 
  and for profit part we check if this element gives us profit greater than we update our answer
"""

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        if len(prices) == 0:
            return 0
        minSoFar = prices[0]
        maxProfit = 0

        for i in range(1,len(prices)):
            if prices[i] < minSoFar:
                minSoFar = prices[i]
            if prices[i] - minSoFar > maxProfit:
                maxProfit = prices[i] - minSoFar

        return (maxProfit)