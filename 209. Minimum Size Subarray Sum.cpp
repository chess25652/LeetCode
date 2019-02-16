class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        // Modify nums to contain cumulative sums
        
        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i-1];
        
        // Now, go through the list with an index variable j.
        // This is the potential endpoint of a subarray containing a sum at least s.
        // Keep track of the largest possible i such that the subarray nums[i..j] has sum at least s.
        // Keep track of the length of the shortest such subarray we find.
        
        int min = nums.size() + 1; // Not found any yet value, will be changed to 0 if it stays no value
        int i = 0;
        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[j] >= s)
            {
                // In this case, there exists some i such that nums[i..j] contains a subarray with sum at least s.
                // The current value of i is guaranteed to hold.
                // Here, increase i to the maximum possible such that this still holds.
                // newsum means the sum we'd have if i were increased by 1.
                int newsum;
                while (i < j) // if i == j, we can't increase i more anyway
                {
                    newsum = nums[j] - nums[i];
                    if (newsum >= s)
                        ++i;
                    else
                        break;
                }
                
                if (j - i + 1 < min)
                    min = j - i + 1;
            }
        }
        if (min > nums.size()) // haven't found any
            return 0;
        else
            return min;
    }
};