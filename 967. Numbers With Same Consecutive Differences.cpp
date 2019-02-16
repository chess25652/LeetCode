class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K)
    {        
        vector<int> solutions;
        if (N == 1) // All 1 digit numbers
        {
            for (int i = 0; i <= 9; ++i)
                solutions.push_back(i);
            return solutions;
        }
        
        if (K == 0) // All digits the same
        {
            for (int i = 1; i <= 9; ++i)
                solutions.push_back(alternating(i, N, K));
            return solutions;
        }
        else if (K >= 5) // Simple: all solution ints must be alternating digits
                    // so solve using iteration
        {
            for (int start = 1; start <= 9; ++start) // starting digit
            {
                if (start + K <= 9) // start is small enough to go up
                {
                    // Only solution is alternation: start, start+K, start, start+K, ...
                    solutions.push_back(alternating(start, N, K));
                }
                else if (start - K >= 0) // start is small enough to go down
                {
                    // Only solution is alternation: start, start-K, start, start-K, ...
                    solutions.push_back(alternating(start, N, -K));
                }
            }
            return solutions;
        }
        else //recursion
        {
            // base case (N==1) already handled at top of function
            vector<int> lowerSet = numsSameConsecDiff(N-1, K);
            for (int num : lowerSet)
            {
                if (num != 0)
                {
                    int lastDigit = num % 10;
                    if (lastDigit+K <= 9)
                        solutions.push_back(num*10 + lastDigit+K);
                    if (lastDigit-K >= 0)
                        solutions.push_back(num*10 + lastDigit-K);
                }
            }
            return(solutions);
        }
    }
    int alternating(int start, int N, int K)
    {
        int evens = start; // even positions counting forward, 0-based
        int odds = start + K;
        
        int number = evens; // since position 0 is even
        for (int i = 1; i < N; ++i)
        {
            number *= 10;
            number += (i % 2 ? odds : evens);
        }
        return number;
    }
};