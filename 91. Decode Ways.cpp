class Solution {
public:
    int numDecodings(string s)
    {
        // a 1- or 0-long message has one decoding, unless it contains one 0.
        
        if (s.length() == 0)
            return 1;
        
        if (s.length() == 1)
            return(s[0] == '0' ? 0 : 1);
        
        // go backwards, figuring out the decode ways for the substr starting at n.
        // start with n being the second to last character (we know it exists).
        // if at n there's two ways to decode (e.g. "2..." or "26..."),
        // add the answers for n+1 and n+2.
        
        // next1 is the # of decode ways starting at the substring ahead;
        // next2, starting at the substring 2 indexes ahead.
        // At first, next2 corresponds to the empty string, and next1 to the last letter.
        int next2 = 1;
        int next1 = s[s.length()-1] == '0' ? 0 : 1; // cannot decode a single 0
        int ways;
        for (int n = s.length() - 2; n >= 0; --n)
        {
            if (s[n] == '0') // cannot decode a message starting with 0
                ways = 0;
            else if (s[n] == '1' || s[n] == '2' && s[n+1] <= '6') // valid double digit number
                ways = next1 + next2;
            else
                ways = next1;
            
            next2 = next1;
            next1 = ways;
        }
        return ways;
    }
};
