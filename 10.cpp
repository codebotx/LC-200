class Solution
{
public:
	int numJewelsInStones(string jewels, string stones)
	{
		unordered_map<char, int> map;
		int ans = 0;
		for (auto s : jewels)
			map[s] = 1;
		for (auto s : stones)
			if (map.find(s) != map.end())
				ans++;
		return ans;
	}
};