class Solution
{
public:
	vector<int> constructRectangle(int area)
	{
		// Find closest two factors of area
		for (int n = (int)sqrt(area); n >= 1; --n)
		{
			// if n is a factor of area, then the solution must be [area/n, n]
			if (area % n == 0)
			{
				vector<int> result = { area / n, n };
				return result;
			}
		}
		// Shouldn't happen, just for "correctness"
		vector<int> result = { area, 1 };
		return result;
	}
};