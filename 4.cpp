class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		if (s.empty())
			return 0;
		vector<char> rep;
		vector<int> v;
		int count = 0;
		int maxi = 0;
		for (int i = 0; i < s.length(); i++)
		{
			auto it = find(rep.begin(), rep.end(), s[i]);
			if (it == rep.end())
			{
				rep.push_back(s[i]);
				count++;
				v.push_back(count);
			}
			else
			{
				rep.erase(rep.begin(), ++it);

				count = rep.size();

				rep.push_back(s[i]);

				count++;
			}
		}
		if (v.empty())
			return s.length();
		else
			return *max_element(v.begin(), v.end());
	}
};