"""
N-Queens
https://leetcode.com/problems/n-queens/description/

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
"""

""" 
Intuition
This is a classical problem in combinatorial optimization and can be solved using recursion and backtracking.
The key intuition behind the N Queens problem is to place a queen in each row of the chessboard, starting from the first row. 
To place a queen in a row, you need to find a safe position for it. A position is considered safe if no other queen can attack it. 
A queen can attack another queen if they are in the same column, row, or diagonal.
So, the algorithm works by iterating through each row of the chessboard, and for each row, it tries to place a queen in each column of that row. 
If a queen can be placed in a column, the algorithm moves on to the next row and tries to place a queen in that row. 
If a safe position cannot be found for a queen in a row, the algorithm backtracks and tries a different position for the queen in the previous row.
""" 

"""
Algorithm 
1. In every row we will check if queen can be placed in any of the column if yes then place it 
2. Move to next row 
3. If it is not possible then back track to previous function and remove the queen from that place and again iterate for the position  
4. Before placing check for the column, left diagonal and right diagonal
5. Base case is very straight forward if we have placed all the queens then add the board in the result 
"""
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        
        res = []
        board = [["."] * n  for _ in range(n)]

        def Answer(r):
            # base case 
            # agar sare queens place kar di toh ans ki copy banao aur res mein append karo
            if r == n:
                temp = ["".join(val) for val in board]
                res.append(temp)
                return 
            
            # sare columns mein check kar rha hu kidhar place kar sakte hai
            for c in range(n):
                if isItSafe(board,r,c):
                    board[r][c] = "Q"
                    Answer(r+1) 
                    board[r][c] = "."
        
        def isItSafe(board,r,c):
            
            # column mein check kar rha hu
            for i in range(r - 1 , -1 ,-1 ):
                if board[i][c] == 'Q':
                    return False     
            
            # left diagonal 
            i , j = r - 1 , c -1 

            while i >= 0 and j >= 0:
                if board[i][j] == "Q":
                    return False 
                i -= 1 
                j -= 1 

            # right diagonal
            
            i , j = r -1 , c + 1

            while i >= 0 and j < n:
                if board[i][j] == "Q":
                    return False 
                i -= 1 
                j += 1 
            
            return True

        Answer(0)
        return res 