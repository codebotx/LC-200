class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		vector<int> res;
		for (auto i = nums.begin(); i != nums.end(); i++)
		{
			for (auto j = i + 1; j != nums.end(); j++)
			{
				if (*i + *j == target)
				{
					int it = i - nums.begin();
					int jt = j - nums.begin();
					res.push_back(it);
					res.push_back(jt);
					return res;
				}
			}
		}
		return res;
	}
};