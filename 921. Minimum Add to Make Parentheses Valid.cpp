class Solution {
public:
    int minAddToMakeValid(string S) {
        int errors = 0;
        int openparens = 0;
        for (int i = 0; i < S.length(); ++i)
        {
            if (S[i] == '(')
                openparens++;
            else // closing paren
            {
                if (openparens == 0) // error: trying to close a paren that wasn't opened
                    ++errors;
                else
                    openparens--;
            }
        }
        return(errors + openparens); // returns errors so far + parens that weren't closed at the end
    }
};
