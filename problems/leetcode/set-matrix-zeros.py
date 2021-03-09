class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # O(1) approach
        i_row = -1
        j_col = -1
        
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == 0:
                    i_row = i
                    j_col = j
                    break
        if i_row == -1 and j_col == -1:
            return
        
        for i in range(len(matrix)):
            if matrix[i][j_col] != 0:
                matrix[i][j_col] = 1
            
        for j in range(len(matrix[i_row])):
            if matrix[i_row][j] != 0:
                matrix[i_row][j] = 1
        
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == 0: # row i, col j
                    matrix[i][j_col] = 0 # Represent horizontal row
                    matrix[i_row][j] = 0 # Represent vertical column
                    
        for i in range(len(matrix)):
            if i == i_row:
                continue
            for j in range(len(matrix[i])):
                if j == j_col:
                    continue
                if matrix[i][j_col] == 0 or matrix[i_row][j] == 0:
                    matrix[i][j] = 0
                    
        for i in range(len(matrix)):
            matrix[i][j_col] = 0
        for j in range(len(matrix[i_row])):
            matrix[i_row][j] = 0
                
                    
        # O(m + n) approach
        # rows = [1] * len(matrix)
        # cols = [1] * len(matrix[0])
        # for i in range(len(matrix)):
        #     for j in range(len(matrix[i])):
        #         if matrix[i][j] == 0:
        #             rows[i] = 0
        #             cols[j] = 0
        #             
        # for i in range(len(matrix)):
        #     for j in range(len(matrix[i])):            
        #         if rows[i] == 0 or cols[j] == 0:
        #             matrix[i][j] = 0
                    
        
        
        
        