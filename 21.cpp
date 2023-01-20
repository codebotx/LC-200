class Solution
{
public:
	vector<string> findRepeatedDnaSequences(string s)
	{
		unordered_map<string, int> map;
		vector<string> ans;
		for (int i = 0; i < s.size(); i++)
		{
			if (i + 10 <= s.size())
			{
				string sub = s.substr(i, 10);
				map[sub]++;
			}
		}
		for (auto it = map.begin(); it != map.end(); it++)
			if ((it->second) > 1)
				ans.push_back(it->first);
		return ans;
	}
};