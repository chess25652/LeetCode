bool comparePairs(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return (a.first > b.first); // higher h goes first
    else
        return (a.second < b.second); // if same h, lower k goes first
}

class Solution {
public:
    
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people)
    {
        vector<pair<int, int>> result(people);
        // Sort people in height nonincreasing order, so that on each insertion
        // there won't be any shorter elements than the one being inserted
        
        std::sort(result.begin(), result.end(), comparePairs);
        
        // Insertion sort
        for (int i = 1; i < result.size(); ++i)
        {
            // Since all elements in [0..i-1] are taller or equal height as element [i],
            // element [i] (save) goes at its k (save.second)
            pair<int, int> save = result[i];
            for (int x = i; x > save.second; --x)
                result[x] = result[x-1];
                
            // Insert save at this position.
            result[save.second] = save;
        }
        
        return result;
    }
};