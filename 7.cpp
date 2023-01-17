class Solution
{
public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		set<vector<int>> s;
		int check = INT_MIN;
		for (auto it = nums.begin(); it != nums.end(); it++)
		{
			if (*it != check)
			{
				check = *it;
				auto itl = it + 1;
				auto itr = nums.end() - 1;
				while (itr > itl)
				{
					if (*it + *itl + *itr == 0)
					{
						vector<int> v;
						v.push_back(*it);
						v.push_back(*itl);
						v.push_back(*itr);
						s.insert(v);
						itr--;
					}
					else if (*it + *itl + *itr > 0)
						itr--;
					else if (*it + *itl + *itr < 0)
						itl++;
				}
			}
		}
		vector<vector<int>> res(s.begin(), s.end());
		return res;
	}
};