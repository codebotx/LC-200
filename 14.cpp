class Solution
{
public:
	bool isHappy(int n)
	{
		if (n == 1)
			return true;
		int k = 100;
		unordered_map<int, int> map;
		while (k)
		{
			int sumofsquares = 0;
			while (n / 10 != 0)
			{
				sumofsquares += (n % 10) * (n % 10);
				n = (int)n / 10;
			}
			sumofsquares += n * n;
			map[sumofsquares] = 1;
			n = sumofsquares;
			k--;
		}

		if (map.find(1) != map.end())
			return true;
		else
			return false;
	}
};