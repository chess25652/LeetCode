class Solution {
public:
    string strWithout3a3b(int A, int B)
    {
        int total = A + B;
        if (total == 0)
            return("");
        
        char *result = new char[total+1];
        result[total] = '\0';
        
        int Astreak = 0, Bstreak = 0;
        for (int i = 0; i < total; ++i)
        {
            if (Astreak >= 2) // must add 'b'
            {
                result[i] = 'b';
                Astreak = 0;
                Bstreak = 1;
                --B; // One less 'b' to add
            }
            else if (Bstreak >= 2) // must add 'a'
            {
                result[i] = 'a';
                Astreak = 1;
                Bstreak = 0;
                --A;
            }
            else // we can add either, so add the one we have more of left
            {
                if (A > B)
                {
                    result[i] = 'a';
                    ++Astreak;
                    Bstreak = 0;
                    --A;
                }
                else
                {
                    result[i] = 'b';
                    ++Bstreak;
                    Astreak = 0;
                    --B;
                }
            }
        }
        
        return(result);
    }
};