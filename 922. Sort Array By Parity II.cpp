class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A)
    {
        vector<int> even, odd;
        
        for (int i : A)
            if (i % 2 == 0)
                even.push_back(i);
            else
                odd.push_back(i);
        
        for (int i=0; i < A.size(); ++i)
        {
            if (i % 2 == 0)
                A[i] = even[i/2];
            else
                A[i] = odd[i/2];
        }
        
        return A;
    }
};
