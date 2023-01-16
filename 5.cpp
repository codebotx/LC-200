class Solution
{
public:
	void reverseString(vector<char> &s)
	{
		auto left = s.begin();
		auto right = s.end() - 1;
		cout << *left << " " << *right;
		char sw;
		while (left < right)
		{
			sw = *left;
			*left = *right;
			*right = sw;
			left++;
			right--;
		}
	}
};