bool decrSort(int a, int b) { return( a > b ); }

class Solution {
public:
    int largestPerimeter(vector<int>& A)
    {
        std::sort(A.begin(), A.end(), decrSort);
        
        int max = 0;
        for (int i = 0; i < A.size()-2; ++i) // leave space for the two smaller sides (a, b)
        {
            if (A[i+1] + A[i+2] > A[i]) // valid triangle
            {
                int perimeter = A[i+1] + A[i+2] + A[i];
                if (perimeter > max)
                    max = perimeter;
            }
        }
        
        return max;
    }
};