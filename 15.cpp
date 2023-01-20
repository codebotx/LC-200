class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs)
	{
		vector<vector<string>> res;
		unordered_map<string, vector<string>> map;

		for (int i = 0; i < strs.size(); i++)
		{
			string test = strs[i];
			sort(test.begin(), test.end());
			map[test] = {};
		}
		for (int i = 0; i < strs.size(); i++)
		{
			string test = strs[i];
			sort(test.begin(), test.end());
			map[test].push_back(strs[i]);
		}
		for (auto x : map)
			res.push_back(x.second);
		return res;
	}
};