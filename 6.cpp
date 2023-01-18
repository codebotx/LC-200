class Solution
{
public:
	int trap(vector<int> &height)
	{
		int score = 0, max_ = INT_MIN;
		int left[height.size()];
		int right[height.size()];

		for (int i = 0; i < height.size(); i++)
		{
			max_ = max(max_, height[i]);
			left[i] = max_;
		}
		max_ = INT_MIN;
		for (int i = height.size() - 1; i >= 0; i--)
		{
			max_ = max(max_, height[i]);
			right[i] = max_;
		}
		for (int i = 0; i < height.size(); i++)
		{
			if (left[i] > height[i] && right[i] > height[i])
				score += min(left[i], right[i]) - height[i];
		}

		return score;
	}
};