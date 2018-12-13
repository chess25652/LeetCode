class NumArray {
    vector<int> cumTotal;
public:
    NumArray(vector<int> nums) : cumTotal(nums)
    {
        for (int i = 1; i < cumTotal.size(); ++i)
            cumTotal[i] += cumTotal[i-1];
    }
    
    int sumRange(int i, int j)
    {
        if (i == 0)
            return( cumTotal[j] );
        else
            return( cumTotal[j] - cumTotal[i-1] );
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
