class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        // Sort both arrays
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        
        // Go through both arrays at the same time, starting at index 0.
        // looking for matches. Each match means one such value in the result.
        
        vector<int> result;
        int pos1 = 0, pos2 = 0; // current element indexes
        while (pos1 < nums1.size() && pos2 < nums2.size()) // if one array is done, then the intersection is final
        {
            // If the arrays' elements are equal, then they intersect,
            // so add one copy to the result vector.
            if (nums1[pos1] == nums2[pos2])
            {
                result.push_back(nums1[pos1]);
                ++pos1;
                ++pos2;
            }
            
            // If one array's element is smaller than the other array's,
            // then that smaller element cannot intersect with the other array. So go to the next element.
            else if (nums1[pos1] < nums2[pos2])
                ++pos1;
            else
                ++pos2;
        }
        
        return result;
    }
};