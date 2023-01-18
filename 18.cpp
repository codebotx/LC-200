class Solution
{
public:
	int subarraySum(vector<int> &nums, int k)
	{
		vector<int> prefixsum;
		int sum = 0;
		int ans = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			prefixsum.push_back(sum);
		}
		unordered_map<int, int> map;
		for (int i = 0; i < prefixsum.size(); i++)
		{
			if (prefixsum[i] == k)
				ans++;
			if (map.find(prefixsum[i] - k) != map.end())
				ans += map[prefixsum[i] - k];
			map[prefixsum[i]]++;
		}
		return ans;
	}
};