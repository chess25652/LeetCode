class Solution
{
public:
	bool PredictTheWinner(vector<int>& nums)
	{
		// result tracks how much the player having the move wins by (assuming optimal play).
		// result[len][position] is the result for the interval of length len+1 starting at position pos
		vector<vector<int>> result;

		for (int len = 0; len < nums.size(); ++len)
		{
			result.push_back(vector<int>());
			for (int start = 0; start + len < nums.size(); ++start)
			{
				if (len == 0)
					result[len].push_back(nums[start]);
				else
				{
					// Choose the last number. Your score will be your number minus the second player's gain from the rest
					int a = nums[start + len] - result[len - 1][start];
					// Choose the first number. Your score will be your number minus the second player's gain from the rest
					int b = nums[start] - result[len - 1][start + 1];
					result[len].push_back(a > b ? a : b);
				}
			}
		}
		// Player 1 wins if the result of length nums.size()-1 starting at position 0 is positive or 0
		return(result[nums.size() - 1][0] >= 0);
	}
};