class Solution
{
public:
	bool isvowel(char ch)
	{
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
			return true;
		else
			return false;
	}

public:
	string reverseVowels(string s)
	{
		vector<char> vowelstore;
		for (int i = 0; i < s.size(); i++)
			if (isvowel(s[i]))
				vowelstore.push_back(s[i]);
		for (int i = 0; i < s.size(); i++)
			if (isvowel(s[i]))
			{
				s[i] = *(vowelstore.end() - 1);
				vowelstore.pop_back();
			}
		return s;
	}
};