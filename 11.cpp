class Solution
{
public:
	vector<int> topKFrequent(vector<int> &nums, int k)
	{
		map<int, int> map;
		multimap<int, int> res;
		for (int i = 0; i < nums.size(); i++)
		{
			if (map.find(nums[i]) != map.end())
				map[nums[i]]++;
			else
				map[nums[i]] = 1;
		}
		for (auto it = map.begin(); it != map.end(); it++)
			// res[it->second]=it->first;
			res.insert(pair<int, int>(it->second, it->first));

		vector<int> ans;

		for (auto it = res.end(); ans.size() != k + 1; it--)
			ans.push_back(it->second);

		ans.erase(ans.begin());

		return ans;
	}
};