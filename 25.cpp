// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
	int firstBadVersion(int n)
	{
		int low = 1;
		long long int high = n;
		if (n == 1)
			return 1;

		while (low < high)
		{
			long long int mid = (low + high) / 2;
			if (isBadVersion(mid) == 1)
			{
				if (isBadVersion(mid - 1) == 0)
					return mid;
				else
					high = mid;
			}
			else if (isBadVersion(mid) == 0)
			{
				if (isBadVersion(mid + 1) == 1)
					return mid + 1;
				else
					low = mid;
			}
		}
		return 0;
	}
};