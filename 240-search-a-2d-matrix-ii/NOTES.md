EFFICIENT APPROACH -> O ( M + N )
​
As the rows are sorted -> matrix[i][j] < matrix[i][j+1]
As the columns are sorted -> matrix[i][j] >matrix[i-1][j]
​
Hence it can be said that :
​
any element right to matrix[i][j] will be greater than it.
any element to the top of matrix[i][j] will be less than it.
So we start searching from BOTTOM_LEFT:
​
if element found -> return TRUE
if matrix[i][j] > target -> move UP.
if matrix[i][j] < target -> move RIGH