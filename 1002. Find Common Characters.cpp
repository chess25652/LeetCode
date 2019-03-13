class Solution {
public:
    vector<string> commonChars(vector<string>& A)
    {
        // Step 1: Load char freq info of first string into count
        int count[26] = { 0 };
        for (int i = 0; i < A[0].length(); ++i)
            ++count[A[0][i] - 'a'];
        
        // Step 2: For each remaining string, if one of its letter quantities
        // is less than count, reduce count to match that string's letter quantity
        int tempCount[26] = { 0 };
        for (int strI = 1; strI < A.size(); ++strI)
        {
            for (int i = 0; i < A[strI].length(); ++i)
                ++tempCount[A[strI][i] - 'a'];
            
            for (int i = 0; i < 26; ++i)
            {
                if (tempCount[i] < count[i])
                    count[i] = tempCount[i];
                tempCount[i] = 0; // Reset tempCount for the next string
            }
        }
        
        // Step 3: Put this all into a list, as our answer is required in this form
        vector<string> result;
        for (int i = 0; i < 26; ++i)
            for (int freq = 0; freq < count[i]; ++freq)
                result.push_back(string(1, (char)('a' + i)));
        
        return result;
    }
};