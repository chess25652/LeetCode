class Solution {
public:
    bool buddyStrings(string A, string B)
    {
        if (A.length() != B.length() || A.length() < 2) // you cannot swap 2 letters if there's less than that total
            return false;
        
        // we should return true if there's 2 differences that can be resolved by a swap,
        //                    or if they're the same string, and A (or B) contains a duplicate letter
        
        // this is for seeing if there's any duplicate letter in A
        bool letter[26] = {0};
        bool dupe = false;
        
        // Indexes of where the strings are different
        int i1 = -1, i2 = -1;
        
        for (int i = 0; i < A.length(); ++i)
        {
            if (!dupe) // haven't found any dupe yet
            {
                if (letter[A[i] - 'a'])
                    dupe = true;
                else
                    letter[A[i] - 'a'] = true;
            }
            if (A[i] != B[i])
            {
                if (i1 == -1)
                    i1 = i;
                else if (i2 == -1)
                    i2 = i;
                else // third diff
                    return false;
            }
        }
        
        if (i1 == -1) // same string
            return dupe; // so return true if there's a dupe letter
        
        else if (i2 == -1) // only 1 difference
            return false;
        
        else
            return (A[i1] == B[i2] && A[i2] == B[i1]); // the 2 differences are resolvable by a swap
    }
};
