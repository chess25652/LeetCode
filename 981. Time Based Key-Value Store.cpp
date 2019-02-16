using std::vector;
using std::string;
using std::map;

class TimeMap {
    map<int, string> values;
    map<string, vector<int>> timeMap;
    
    int binsrch(const vector<int> &A, int x) // A cannot be empty
    {
        //// Find the largest number in A no bigger than x
        
        // If no such number, return -1
        if (x < A[0])
            return -1;
        
        // [low .. high] must contain x, if it exists, or be next to where x would be
        int high = A.size()-1;
        int low = 0;
        int mid;
        
        while (low <= high)
        {
            mid = (high + low) / 2;
            if (x == A[mid])
                return A[mid];
            else if (x > A[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        // At this point, if x were in A, it'd be between A[high] and A[low]. A[high] is the smaller number, so it's the answer.
        return A[high];
    }
    
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp)
    {
        // Store value
        values[timestamp] = value;
        
        // Set key entry in timeMap
        
        if (timeMap.count(key) == 1) // Key already exists
            timeMap[key].push_back(timestamp);
        else
        {
            // No key entry exists in the map, so create one
            vector<int> time = {timestamp};
            timeMap[key] = time;
        }
    }
    
    string get(string key, int timestamp)
    {
        // Find the timestamps of the key
        if (timeMap.count(key) == 0) // Key does not exist
            return "";
        else
        {
            int timestamp_prev = binsrch(timeMap[key], timestamp);
            if (timestamp_prev == -1)
                return "";
            else
                return(values[timestamp_prev]);
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */