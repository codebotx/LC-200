class Solution
{
public:
	bool isAnagram(string s, string t)
	{
		if (s.size() != t.size())
			return false;
		unordered_map<char, int> map1, map2;
		for (auto it = s.begin(); it != s.end(); it++)
		{
			if (map1.find(*it) != map1.end())
				map1[*it]++;
			else
			{
				map1[*it] = 1;
			}
		}

		for (auto it = t.begin(); it != t.end(); it++)
		{
			if (map2.find(*it) != map1.end())
				map2[*it]++;
			else
			{
				map2[*it] = 1;
			}
		}
		if (map1 == map2)
			return true;
		else
			return false;
	}
};