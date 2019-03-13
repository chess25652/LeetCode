class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> solution;
        
        for (int i = left; i <= right; ++i)
        {
            if (isSelfDiv(i))
                solution.push_back(i);
        }
        
        return solution;
    }
    
    bool isSelfDiv(int i)
    {
        int j = i, d;
        
        while (j != 0)
        {
            d = j % 10;
            if (d == 0 || i % d != 0) // will short circuit if d==0, so we're good
            {
                // not self dividing
                return false;
            }
            j /= 10;
        }
        
        return true;
    }
};
