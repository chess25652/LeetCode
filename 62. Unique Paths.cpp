class Solution {
    // We'll have a m by n array to store the unique paths from (m, n) to the finish.
    // Note: paths[m][n] means paths for the square m up and n left from the finish.
    int **paths;
    
    int findPaths(int m, int n)
    {
        // If we already know the answer, return that
        if (paths[m][n] != 0)
            return paths[m][n];
        
        // Calculate from adding paths down and paths right
        int downPaths = (m == 0) ? 0 : findPaths(m-1, n);
        int rightPaths = (n == 0) ? 0 : findPaths(m, n-1);
        
        paths[m][n] = downPaths + rightPaths;
        
        return(downPaths + rightPaths);
    }
public:
    int uniquePaths(int m, int n)
    {
        // Initialize
        paths = new int*[m];
        for (int i = 0; i < m; ++i)
            paths[i] = new int[n](); // initialize to zero; this represents unknown
        paths[0][0] = 1; // There is one way to get from the finish to the finish
        
        return findPaths(m-1, n-1); // ZERO BASED INDEXING
    }
};