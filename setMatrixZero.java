//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//
//
//Did you use extra space?
//A straight forward solution using O(mn) space is probably a bad idea.
//A simple improvement uses O(m + n) space, but still not the best solution.
//Could you devise a constant space solution?

public class Solution {
    public void setZeroes(int[][] matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int row = matrix.length;
        int col = matrix[0].length;
        
        if (row == 0 || col == 0)
            return;
        
        boolean zerorow = false, zerocol = false;
        
        for (int i = 0; i < col; ++i)
        {
            if (matrix[0][i] == 0)
                zerorow = true;
        }
        
        for (int i = 0; i < row; ++i)
        {
            if (matrix[i][0] == 0)
                zerocol = true;
        }
            
        for (int i = 1; i < row; ++i)
            for (int j = 1; j < col; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    // record the info in first row and first column
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
            
        // setting the zeros    
       for (int i = 1; i < row; ++i)
            for (int j = 1; j < col; ++j)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        
        // setting first row
        if (zerorow)
        {
            for (int i = 0; i < col; ++i)
            {
                matrix[0][i] = 0;
            }
        }
        
        // setting first column
        if (zerocol)
        {
            for (int i = 0; i < row; ++i)
                matrix[i][0] = 0;
        }
        
        
    }
}