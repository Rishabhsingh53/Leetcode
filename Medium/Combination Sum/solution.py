"""
39. Combination Sum
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times.
Two combinations are unique if the frequency of at least one of the chosen numbers is different.
"""
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
    
        res = []
        
        def answer(idx , target , arr ):
          
          if target == 0 :
            res.append(arr[:])
            return 
          
          if target < 0 :
            return 
          
          for i in range(idx , len(candidates)):
            arr.append(candidates[i])
            answer(i , target - candidates[i] , arr)
            arr.pop() # backtrack and remove the added candidate 

        answer(0 , target , [])
        return res 