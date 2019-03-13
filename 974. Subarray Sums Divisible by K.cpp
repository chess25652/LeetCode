inline int mod(int n, int K)
{
    n %= K;
    return( n < 0 ? n + K : n );
}

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K)
    {
        int count = 0;
        std::map<int, int> sums;
        
        A[0] = mod(A[0], K);
        if (A[0] == 0) // first element [0] is divisible by K
            ++count;
        sums[A[0]] = 1;
        
        for (int i = 1; i < A.size(); ++i)
        {
            A[i] = mod(A[i-1] + A[i], K);
            
            // Subarray 0..i is divisible by K
            if (A[i] == 0)
                ++count;
            
            // If another (previous) sum, say 0..5, and 0..i, have the same sum mod K,
            // that means 6..i's sum is 0 mod K. So if 0..i's sum has already been stored,
            // then each time it's been stored is a starting point of a 0-sum-mod-K interval ending at i.
            
            if (sums.find(A[i]) == sums.end()) // A[i] hasn't been stored yet
                sums[A[i]] = 1;
            else
            {
                count += sums[A[i]];
                sums[A[i]] += 1;
            }
        }
        
        return count;
    }
};