class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix = [[0]*n for _ in range(n)]
        #print(matrix)
        
        # use count as the number we fill in with, and four bounds
        top, bottom = 0, n-1 
        left, right = 0, n-1
        value = 1               #to insert in the matrix
        size = n*n
        
        while value <= size:
            # put value into the upper bound of matrix
            if top <= bottom:
                for col in range(left, right + 1):
                    matrix[top][col] = value
                    value += 1
                top += 1
            
            # value into the right bound of matrix
            if left <= right:
                for row in range(top, bottom + 1):
                    matrix[row][right] = value
                    value += 1
                right -= 1
            
            # value into the bottom bound of matrix
            if top <= bottom:
                for col in range(right, left - 1, -1):
                    matrix[bottom][col] = value
                    value += 1
                bottom -= 1
            
            # write count into the left bound of matrix
            if left <= right:
                for row in range(bottom, top - 1, -1):
                    matrix[row][left] = value
                    value += 1
                left += 1
            
        return matrix
        
