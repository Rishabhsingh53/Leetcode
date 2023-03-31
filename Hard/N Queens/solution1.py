
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