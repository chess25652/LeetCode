class Solution {
public:
    bool isUgly(int num)
    {
        if (num < 1)
            return false;
        
        // Remove all factors of 2, 3, 5
        while (num != 1)
        {
            if (num % 2 == 0)
                num /= 2;
            else if (num % 3 == 0)
                num /= 3;
            else if (num % 5 == 0)
                num /= 5;
            else // num is a relative prime of 2, 3, and 5
                return false;
        }
        
        // No factors other than 2, 3, 5 remain.
        return true;
    }
};