class Solution {
public:
    int dominantIndex(vector<int>& nums)
    {
        // Can do with two passes:
        // (1) Find maximum
        // (2) Find whether max is at least twice as large as others
        
        int maxIndex = 0;
        int maxVal = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > maxVal)
            {
                maxIndex = i;
                maxVal = nums[i];
            }
        }
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i != maxIndex && nums[i] * 2 > maxVal)
                return(-1);
        }
        return(maxIndex);
    }
};