bool compPoints(const vector<int> &a, const vector<int> &b)
{
    return( (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]) );
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
    {
        vector<vector<int>> result;
        
        std::sort(points.begin(), points.end(), compPoints);
        
        for (int i = 0; i < K; ++i)
        {
            result.push_back(points[i]);
        }
        
        return result;
    }
};