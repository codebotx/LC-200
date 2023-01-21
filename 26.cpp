class Solution
{
public:
	int findPeakElement(vector<int> &nums)
	{
		if (nums.size() == 1)
			return 0;

		if (nums.size() == 2)
			if (nums[0] > nums[1])
				return 0;
			else
				return 1;

		if (nums[0] > nums[1])
			return 0;
		else if (nums[nums.size() - 1] > nums[nums.size() - 2])
			return nums.size() - 1;

		int low = 1;
		int high = nums.size() - 2;

		while (low < high)
		{

			if (nums[low] > nums[low + 1] && nums[low] > nums[low - 1])
				return low;
			else if (nums[high] > nums[high - 1] && nums[high] > nums[high + 1])
				return high;

			low++;
			high--;
		}

		if (low == high)
			if (nums[low] > nums[low - 1] && nums[low] > nums[low + 1])
				return low;

		return 0;
	}
};