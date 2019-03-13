class Solution {
public:
    vector<string> removeComments(vector<string>& source)
    {
        vector<string> result;
        bool blockOn = false;
        int currStr = 0;
        size_t pos = 0;
        string buffer;
        
        while (currStr < source.size())
        {
            // Look for control sequences: Comment delimiters or newlines
            size_t ctrlPos;
            int type = search(source[currStr], pos, ctrlPos);
            // Four return values:
            // 0: End of line: No comment delimiters found (ctrlPos == string::npos)
            // 1: Found a line comment // at position ctrlPos
            // 2: Found a block comment starter /* at position ctrlPos
            // 3: Found a block comment ender */ at position ctrlPos
            
            if (blockOn) // Block comment on
            {
                if (type == 0) // End of line
                {
                    // Go to the next string
                    ++currStr;
                    pos = 0;
                }
                else if (type == 3) // Comment ender
                {
                    pos = ctrlPos + 2; // skip over the comment ender
                    blockOn = false;
                }
                else
                    pos = ctrlPos + 1; // Discard ctrl sequence, find the next one
            }
            else
            {
                switch (type)
                {
                    case 0: // End of line
                        buffer += source[currStr].substr(pos);
                        if (buffer.length())
                            result.push_back(buffer);
                        buffer = "";
                        ++currStr; // go to the next line
                        pos = 0;
                        break;

                    case 1: // Line comment (//)
                        buffer += source[currStr].substr(pos, ctrlPos - pos);
                        if (buffer.length())
                            result.push_back(buffer);
                        buffer = "";
                        ++currStr; // go to the next line
                        pos = 0;
                        break;

                    case 2: // Block comment starter (/*)
                        buffer += source[currStr].substr(pos, ctrlPos - pos);
                        pos = ctrlPos + 2;
                        blockOn = true;
                        break;
                        
                    case 3: // Block comment ender (*/)
                        buffer += source[currStr].substr(pos, ctrlPos - pos + 1);
                        pos = ctrlPos + 1; // Discard ctrl sequence, find the next one
                        break;
                }
            }
        }
        return result;
    }
    
    // Finds the next control sequence, writes its position to posOut, and returns the ctrl seq type
    int search(const string& str, size_t currPos, size_t& posOut)
    {
        size_t pos = currPos;
        while (true)
        {
            pos = str.find_first_of("/*", pos);
            if (pos == string::npos || pos + 1 == str.length())
            {
                posOut = string::npos;
                return 0;
            }
            if (str[pos] == '/' && str[pos+1] == '/')
            {
                posOut = pos;
                return 1;
            }
            if (str[pos] == '/' && str[pos+1] == '*')
            {
                posOut = pos;
                return 2;
            }
            if (str[pos] == '*' && str[pos+1] == '/')
            {
                posOut = pos;
                return 3;
            }
            ++pos;
        }
    }
};